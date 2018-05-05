#include <string>
#include <iostream>
#include <array>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "buffer.h"

//
//	CONSTANTS
//
/// WINDOW
const unsigned WIDTH = 720;
const unsigned HEIGHT = 480;
const std::string TITLE = "Conway's Game of Life";
const sf::Uint32 STYLE = sf::Style::Close | sf::Style::Titlebar;
const sf::Int32 FRAME_RATE = 60;


//
//	GLOBALS
//
/// ENGINE
sf::RenderWindow window_;
bool running_ = true;	
sf::Clock clock_;
sf::Time next_tick_ = clock_.getElapsedTime();
bool keys_[sf::Keyboard::KeyCount];
sf::Vector2f mouse_pos_;
/// GFX
sf::Texture cursor_t_;
sf::Sprite cursor_;
sf::RectangleShape shape_(sf::Vector2f(10, 10));
/// SFX
sf::Music theme_;
/// GAMEPLAY
std::array<std::array<bool, HEIGHT / 10>, WIDTH/ 10> cell_;


//
//	HEADERS
//
void init();
void handle_input();
void update();
void redraw();


int main(int argc, char ** argv)
{
	init();

	while (running_)
	{
		handle_input();

		if (clock_.getElapsedTime() >= next_tick_)
		{
			update();
			redraw();

			next_tick_ += sf::milliseconds(1000 / FRAME_RATE);
		}

	}

	return 0;
}

void init()
{
	window_.create(sf::VideoMode(WIDTH, HEIGHT), TITLE, STYLE);
	window_.setMouseCursorVisible(false);

	bool a = cursor_t_.loadFromFile("./data/cursor.png");
	cursor_.setTexture(cursor_t_);
	cursor_.setOrigin(sf::Vector2f(cursor_t_.getSize().x >> 1, cursor_t_.getSize().y >> 1));

	theme_.openFromFile("./data/theme.ogg");
	theme_.setLoop(true);
	theme_.play();

	cell_[10][10] = 1;
	cell_[11][11] = 1;
	cell_[11][12] = 1;
	cell_[10][12] = 1;
	cell_[9][12] = 1;
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
			break;
		case sf::Event::KeyReleased:
			keys_[event.key.code] = false;
			break;
		case sf::Event::MouseMoved:
			mouse_pos_ = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
			cursor_.setPosition(mouse_pos_);
			break;
		case sf::Event::LostFocus:
			theme_.pause();
			break;
		case sf::Event::GainedFocus:
			theme_.play();
			break;
		}
	}
}

void update()
{
	cursor_.rotate(1.0f);

}

void redraw()
{
	window_.clear(sf::Color::Black);

	window_.draw(cursor_);

	window_.display();
}
