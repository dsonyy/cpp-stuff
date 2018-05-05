#include <cmath>
#include "core.h"
#include "graph.h"
// 40 0.1 200 0
// n  r   k   l

void draw_graph(sf::RenderWindow & window)
{
	sf::Image graph;
	sf::Texture texture;
	sf::Sprite sprite;

	graph.create(WIDTH, 300, sf::Color(0, 0, 0));

	graph.setPixel(0, 0, sf::Color::Red);
	int x = 0;
	for (int x = 0; x < WIDTH; x++)
	{
		int y = 150 + std::sin(float(x)) * 100.0f;
		graph.setPixel(x, y, sf::Color::Green);

	}

	texture.loadFromImage(graph);
	sprite.setTexture(texture);

	window.draw(sprite);
}