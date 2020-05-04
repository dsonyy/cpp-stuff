#include <string>
#include <iostream>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <ctime>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


//
//	DATA STRUCTURES
//
enum Direction { UP, DOWN, LEFT, RIGHT, NONE };
struct Point
{
	sf::Vector2f pos;
	Direction dir = DOWN;
};

//
//	CONSTANTS
//
/// WINDOW
const unsigned WIDTH = 720;
const unsigned HEIGHT = 480;
std::string TITLE = "Snake";
const sf::Uint32 STYLE = sf::Style::Close | sf::Style::Titlebar;
const int FRAME_RATE = 60;

//
//	GLOBALS
//
/// CORE
sf::RenderWindow window_;
bool running_ = true;	
bool game_over_ = false;
sf::Clock clock_;
sf::Time next_redraw_;
sf::Time next_update_;
bool keys_[sf::Keyboard::KeyCount];
sf::Font font_;
const sf::Time min_game_speed_ = sf::microseconds(2000);
sf::Time game_speed_ = sf::microseconds(10000);

/// GAMEPLAY
Direction input_direction_ = RIGHT;
std::deque<Point> snake_;
int score_ = 0;
float speed_ = 1;
float growth_speed_ = 0.2;
sf::RectangleShape apple_;


//
//	HEADERS
//
/// CORE
void init_sfml();
void init_game();
void handle_input();
void update();
void redraw();
/// GAMEPLAY
void move_snake();
void move_point(Point & point, float offset = speed_);
bool remove_point(const Point & p0, const Point & p1);
bool collid_map(sf::Vector2f p);
bool collid(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f k0, sf::Vector2f k1);
bool collid_apple(sf::Vector2f p0);
void spawn_apple();

int main(int argc, char ** argv)
{
	init_sfml();
	init_game();

	while (running_)
	{
		handle_input();

		if (!game_over_)
		{
			if (clock_.getElapsedTime() >= next_update_)
			{
				update();
				next_update_ += game_speed_;
			}
		}

		if (clock_.getElapsedTime() >= next_redraw_)
		{
			redraw();
			next_redraw_ += sf::milliseconds(1000 / FRAME_RATE);
		}

	}

	return 0;
}

void init_sfml()
{
	window_.create(sf::VideoMode(WIDTH, HEIGHT), TITLE, STYLE);
	font_.loadFromFile("data/Lato-Black.ttf");
}

void init_game()
{
	srand(std::time(0));

	next_redraw_ = clock_.getElapsedTime();
	next_redraw_ = clock_.getElapsedTime();

	Point begin = { sf::Vector2f(150,100), RIGHT };
	Point end = { sf::Vector2f(100,100), RIGHT };

	spawn_apple();

	snake_.push_back(end);
	snake_.push_front(begin);
}

void handle_input()
{
	sf::Event event;

	while (window_.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			running_ = false;
			break;

		case sf::Event::KeyPressed:
			keys_[event.key.code] = true;
			if (event.key.code == sf::Keyboard::Key::Up    && input_direction_ != DOWN)  input_direction_ = UP;
			else if (event.key.code == sf::Keyboard::Key::Down  && input_direction_ != UP)    input_direction_ = DOWN;
			else if (event.key.code == sf::Keyboard::Key::Left  && input_direction_ != RIGHT) input_direction_ = LEFT;
			else if (event.key.code == sf::Keyboard::Key::Right && input_direction_ != LEFT)  input_direction_ = RIGHT;

			break;

		case sf::Event::KeyReleased:
			keys_[event.key.code] = false;
			break;
		}
	}

}

void update()
{
	move_snake();

	if (collid_map(snake_.front().pos))
	{
		game_over_ = true;
	}

	for (auto i = snake_.begin() + 4; i < snake_.end(); i+=2)
	{
		auto a = snake_.front().pos;
		auto b = (snake_.begin() + 1)->pos;
		auto c = i->pos;
		auto d = (i - 1)->pos;

		if (collid(a, b, c, d))
		{
			game_over_ = true;
		}
	}

	if (collid_apple(snake_.front().pos))
	{
		spawn_apple();
		score_++;
		if (min_game_speed_ <= game_speed_ - sf::microseconds(1000))
		{
			game_speed_ -= sf::microseconds(1000);
		}
		else
		{
			growth_speed_ = 0;
		}

	}
}

void redraw()
{
	if (!game_over_) window_.clear(sf::Color::Black);
	else             window_.clear(sf::Color::Red);

	sf::Text score("score:  " + std::to_string(score_), font_, 12);
	score.setPosition(20, 20);
	window_.draw(score);

	sf::VertexArray snake(sf::PrimitiveType::LinesStrip);
	for (auto & i : snake_)
	{
		snake.append(sf::Vertex(i.pos));
	}
	window_.draw(snake);

	window_.draw(apple_);
	window_.display();
}

void move_snake()
{
	if (std::floor(snake_.begin()->pos.x) != std::floor((snake_.begin() + 1)->pos.x) ||
		std::floor(snake_.begin()->pos.y) != std::floor((snake_.begin() + 1)->pos.y))
	{
		if (input_direction_ == UP && snake_.front().dir != UP) snake_.push_front({ snake_.front().pos, UP });
		else if (input_direction_ == DOWN && snake_.front().dir != DOWN)  snake_.push_front({ snake_.front().pos, DOWN });
		else if (input_direction_ == LEFT && snake_.front().dir != LEFT)  snake_.push_front({ snake_.front().pos, LEFT });
		else if (input_direction_ == RIGHT && snake_.front().dir != RIGHT) snake_.push_front({ snake_.front().pos, RIGHT });
	}

	move_point(snake_.front());
	move_point(snake_.back());
	if (remove_point(*(snake_.end() - 1), *(snake_.end() - 2)))
	{
		snake_.pop_back();
		snake_.back().dir = (snake_.end() - 2)->dir;
	}
	move_point(snake_.back(), -growth_speed_);
}

void move_point(Point & point, float offset)
{
	switch (point.dir)
	{
	case UP:    point.pos.y -= offset; break;
	case DOWN:  point.pos.y += offset; break;
	case LEFT:  point.pos.x -= offset; break;
	case RIGHT: point.pos.x += offset; break;
	default: break;
	}
}

bool remove_point(const Point & p0, const Point & p1)
{
	bool ret = false;

	switch (p0.dir)
	{
	case UP:    if (p0.pos.y <= p1.pos.y) ret = true; break;
	case DOWN:  if (p0.pos.y >= p1.pos.y) ret = true; break;
	case LEFT:  if (p0.pos.x <= p1.pos.x) ret = true; break;
	case RIGHT: if (p0.pos.x >= p1.pos.x) ret = true; break;
	default: break;
	}

	return ret;
}

bool collid_map(sf::Vector2f p)
{
	if (p.x < 0 || p.x > WIDTH || p.y < 0 || p.y > HEIGHT)
	{
		return true;
	}

	return false;
}

bool collid(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f k0, sf::Vector2f k1)
{
	 // p0.x <   p1.x
	 // p0.y ==  p1.y
	 // 
	 // k0.x == k1.x
	 // k0.y <  k1.y

	if (p0.x == p1.x && k0.y == k1.y)
	{
		auto tp0 = p0;
		p0 = k1;
		k1 = p1;
		p1 = k0;
		k0 = tp0;
	}

	if (p0.x > p1.x)
	{
		auto t0 = p0;
		p0 = p1;
		p1 = t0;
	}

	if (k0.y > k1.y)
	{
		auto t0 = k0;
		k0 = k1;
		k1 = t0;
	}

	if (k0.x >= p0.x &&
		k0.x <= p1.x &&
		k0.y <= p0.y &&
		k0.y <= p1.y &&
			  
		k1.x >= p0.x &&
		k1.x <= p1.x &&
		k1.y >= p0.y &&
		k1.y >= p1.y)
	{
		return true;
	}

	return false;
}

bool collid_apple(sf::Vector2f p)
{
	if (p.x >= apple_.getPosition().x && p.x <= apple_.getPosition().x + apple_.getSize().x &&
		p.y >= apple_.getPosition().y && p.y <= apple_.getPosition().y + apple_.getSize().y)
	{
		return true;
	}

	return false;
}

void spawn_apple()
{
	auto x = rand() % int(WIDTH - 100) + 50;
	auto y = rand() % int(HEIGHT - 100) + 50;
	auto size = rand() % 20 + 10;

	apple_.setPosition(sf::Vector2f(x, y));
	apple_.setSize(sf::Vector2f(size, size));
	apple_.setFillColor(sf::Color::Red);

}
