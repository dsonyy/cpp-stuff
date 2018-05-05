#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

struct Rectangle
{
	float x = 0;
	float y = 0;
	float w = 0;
	float h = 0;
};

struct Circle
{
	float cx = 0;
	float cy = 0;
	float r = 0;
};

struct Line
{
	float x0 = 0.0f;
	float y0 = 0.0f;
	float x1 = 0.0f;
	float y1 = 0.0f;
};

struct Elipse
{
	Line * rx;
	Line * ry;
} ball;

struct Rect
{
	Line * side[4];
};

struct BallForce
{
	float x = 1.0;
	float y = 0.0;
} ball_force;

const int WIDTH = 720;
const int HEIGHT = 720;

const int MAX_PLAYER_HEIGHT = 75;
const int MIN_PLAYER_HEIGHT = 50;
const float PLAYER_SPEED = 1.0;

enum UsedKeys { W, S, UP, DOWN, A, D, LEFT, RIGHT, USED_KEYS_NUM };
bool keys[USED_KEYS_NUM];

std::vector<Rectangle> players;
std::vector<Circle> balls;

std::vector<Line> lines;

///////////////////////////////////////////////////////////////////////////////
// SFML
///////////////////////////////////////////////////////////////////////////////

sf::RenderWindow * window;
sf::VertexArray * figures;

///////////////////////////////////////////////////////////////////////////////
// HEADERS
///////////////////////////////////////////////////////////////////////////////

void SFMLInit();
void InitGame();
void Render();
void Logic();
bool IsPointInsideRect(const Rectangle & rect, float x, float y);

int main(int argc, char ** argv)
{
	SFMLInit();
	InitGame();

	bool running = true;
	double next_rende;
	double next_logic;
	sf::Event event;

	while (running)
	{
		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				running = false;
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:		keys[UP] = true;	break;
				case sf::Keyboard::Down:	keys[DOWN] = true;	break;
				case sf::Keyboard::W:		keys[W] = true;		break;
				case sf::Keyboard::S:		keys[S] = true;		break;
				case sf::Keyboard::D:		keys[D] = true;		break;
				case sf::Keyboard::A:		keys[A] = true;		break;
				case sf::Keyboard::Left:	keys[LEFT] = true;	break;
				case sf::Keyboard::Right:	keys[RIGHT] = true;	break;
				}
				break;
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:		keys[UP] = false;	break;
				case sf::Keyboard::Down:	keys[DOWN] = false;	break;
				case sf::Keyboard::W:		keys[W] = false;	break;
				case sf::Keyboard::S:		keys[S] = false;	break;
				case sf::Keyboard::D:		keys[D] = false;	break;
				case sf::Keyboard::A:		keys[A] = false;	break;
				case sf::Keyboard::Left:	keys[LEFT] = false;	break;
				case sf::Keyboard::Right:	keys[RIGHT] = false;break;
				}
				break;
			}
		}

		//if (al_get_time() >= next_logic)
		{
			Logic();
			//next_logic = al_get_time() + 1.0 / 180.0;
		}

		//if (al_get_time() >= next_render)
		{
			Render();
			//next_render = al_get_time() + 1.0 / 60.0;
		}

	}


	return 0;
}

void SFMLInit()
{
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Pong");
	figures = new sf::VertexArray(sf::PrimitiveType::Quads, 4);
	(*figures)[0].position = sf::Vector2f(0, 0);
	(*figures)[1].position = sf::Vector2f(100, 0);
	(*figures)[2].position = sf::Vector2f(100, 100);
	(*figures)[3].position = sf::Vector2f(0, 100);

}

void InitGame()
{
	srand(time(NULL));

	lines.push_back({ 500,10,100,300 });
	lines.push_back({ 100,300,500, HEIGHT - 10 });
	lines.push_back({ 700,10,700,HEIGHT - 10 });

	lines.push_back({ 610,200, 610,220});
	lines.push_back({ 600,210, 620,210 });
	ball = { &lines.back(), &lines.back() - 1 };


	for each (bool key in keys)
	{
		key = false;
	}

}

void Render()
{
	window->clear();
	window->draw(*figures);


	window->display();

}

void Logic()
{
	//if (keys[UP] && players[1].y > 0) players[1].y -= PLAYER_SPEED;
	//if (keys[DOWN] && players[1].y + players[1].h < HEIGHT) players[1].y += PLAYER_SPEED;

	//if (keys[W] && players[0].y > 0) players[0].y -= PLAYER_SPEED;
	//if (keys[S] && players[0].y + players[0].h < HEIGHT) players[0].y += PLAYER_SPEED;

	//if (keys[A] && players[3].x > 0) players[3].x -= PLAYER_SPEED;
	//if (keys[D] && players[3].x + players[3].w < WIDTH) players[3].x += PLAYER_SPEED;

	//if (keys[LEFT] && players[2].x > 0) players[2].x -= PLAYER_SPEED;
	//if (keys[RIGHT] && players[2].x + players[2].w < WIDTH) players[2].x += PLAYER_SPEED;

	//bool collision = false;
	//for each (auto object in players)
	//{
	//	for each (auto ball in balls)
	//	{
	//		if (IsPointInsideRect(object, ball.cx - (ball.r / 2), ball.cy - (ball.r / 2)) ||
	//			IsPointInsideRect(object, ball.cx + (ball.r / 2), ball.cy - (ball.r / 2)) ||
	//			IsPointInsideRect(object, ball.cx + (ball.r / 2), ball.cy + (ball.r / 2)) ||
	//			IsPointInsideRect(object, ball.cx - (ball.r / 2), ball.cy + (ball.r / 2)))
	//		{
	//			ball_force.x = -(object.x + (object.w / 2) - ball.cx);
	//			ball_force.y = -(object.y + (object.h / 2) - ball.cy);
	//		}
	//	}
	//}

	//balls[0].cx += ball_force.x / 10;
	//balls[0].cy += ball_force.y / 10;
}

bool IsPointInsideRect(const Rectangle & rect, float x, float y)
{
	if (x >= rect.x &&
		x <= rect.x + rect.w &&
		y >= rect.y &&
		y <= rect.y + rect.h)
	{
		return true;
	}

	return false;
}