#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <experimental/filesystem>

#include <SFML\Graphics.hpp>

namespace fs = std::experimental::filesystem;

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

static sf::Color buffer[HEIGHT][WIDTH];
sf::RenderWindow window;
sf::Texture texture;
sf::Sprite sprite;
std::vector<sf::Image> palettes;

void clear()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			buffer[y][x] = sf::Color::Black;
		}
	}
}

void draw_circle(int cx, int cy, int radius, const sf::Image & palette)
{
	for (int y = cy - radius + 1; y < cy + radius; y++)
	{
		for (int x = cx - radius + 1; x < cx + radius; x++)
		{
			float distance = sqrt(pow(cx - x, 2) + pow(cy - y, 2));

			if (distance < radius)
				buffer[y][x] = palette.getPixel(distance / radius * 255, 0);

		}
	}
}

int main()
{
	window.create(sf::VideoMode(800, 800), "Circles");
	texture.create(800, 800);
	sprite.setTexture(texture);

	for (auto & p : fs::directory_iterator("palettes"))
	{
		palettes.push_back(sf::Image());
		palettes.back().loadFromFile(p.path().filename().string());
	}

	clear();

	sf::Clock clock;
	sf::Time next_tick = clock.getElapsedTime();
	sf::Event ev;
	bool running = true;
	size_t palette_number = 0;
	while (1)
	{
		while (window.pollEvent(ev))
		{
			if (sf::Event::Closed) running = false;
			if (sf::Event::KeyReleased)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					palette_number + 1 < palettes.size() ?
						palette_number++ :
						palette_number = 0;
				}
			}
		}

		if (clock.getElapsedTime() > next_tick)
		{
			texture.update((sf::Uint8*)buffer);
			window.clear(sf::Color(0, 0, 0));
			window.draw(sprite);
			window.display();


			next_tick += sf::milliseconds(500);
		}
	}


	return 0;
}