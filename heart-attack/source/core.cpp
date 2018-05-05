#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "core.h"
#include "graph.h"

void loop()
{
	sf::RenderWindow window;
	CoreContext core;
	sf::Clock clock;
	sf::Time tick;

	init_sfml(window);
	init_game();

	while (core.running)
	{
		handle_input(window, core);

		if (clock.getElapsedTime() >= tick)
		{
			update();
			redraw(window);

			tick += sf::milliseconds(1000 / MAX_FPS);
		}

	}
}

void init_sfml(sf::RenderWindow & window)
{
	window.create(
		sf::VideoMode(WIDTH, HEIGHT),
		TITLE, 
		STYLE);
	window.setMouseCursorVisible(true);
}

void init_game()
{

}

void handle_input(sf::RenderWindow & window, CoreContext & core)
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			core.running = false;
			break;
		case sf::Event::KeyPressed:
			core.keys[event.key.code] = true;
			break;
		case sf::Event::KeyReleased:
			core.keys[event.key.code] = false;
			break;
		}
	}
}

void update()
{
}

void redraw(sf::RenderWindow & window)
{
	window.clear(sf::Color::Black);

	draw_graph(window);

	window.display();
}