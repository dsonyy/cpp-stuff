#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


//
//   WINDOW CONSTANTS
//
const unsigned WIDTH = 720;
const unsigned HEIGHT = 480;
const std::string TITLE = "Heart Attack!";
const sf::Uint32 STYLE = sf::Style::Default;
const sf::Int32 MAX_FPS = 60;

struct CoreContext
{
	bool running = true;
	bool pause = false;
	bool focus = true;
	bool keys[sf::Keyboard::KeyCount] = {};
};

void loop();

void init_sfml(sf::RenderWindow & window);

void init_game();

void handle_input(sf::RenderWindow & window, CoreContext & core);

void update();

void redraw(sf::RenderWindow & window);
