#include <iostream>
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;
#include <SFML/Graphics.hpp>

#define WIDTH 300
#define HEIGHT 300

void clear(sf::Color * buffer)
{
	for (int i = 0; i < WIDTH * HEIGHT; i++)
	{
		buffer[i] = sf::Color::Black;
	}
}

void draw_circle(int cx, int cy, double radius, const sf::Image & palette, sf::Color * buffer)
{
	for (int y = cy - radius + 1; y < cy + radius; y++)
	{
		for (int x = cx - radius + 1; x < cx + radius; x++)
		{
			double distance = sqrt(pow(cx - x, 2) + pow(cy - y, 2));

			int xx = distance / radius * palette.getSize().x;
			if (distance < radius)
				buffer[y * WIDTH + x] = palette.getPixel(xx, 0);
		}
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Not Only Circles", sf::Style::Close | sf::Style::Titlebar);
	
	sf::Color * buffer;
	buffer = new sf::Color [WIDTH * HEIGHT];

	sf::Texture texture;
	texture.create(WIDTH, HEIGHT);
	
	sf::Sprite sprite;
	sprite.setTexture(texture);

	bool running = true;
	size_t current = 0;
	double radius = 100;
	sf::Event event;

	std::vector<sf::Image> palettes;
	
	for (auto & path : fs::directory_iterator("res"))
	{
		palettes.push_back(sf::Image());
		palettes.back().loadFromFile(path.path().string());
	}

	if (palettes.empty())
	{
		return 0;
	}

	while (running)
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed: 
				running = false; 
				break;
			case sf::Event::KeyPressed:
				bool q = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
					&& current + 1 < palettes.size()) 
				{
					current++;
					clear(buffer);
					draw_circle(WIDTH / 2, HEIGHT / 2, radius, palettes[current], buffer);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
					&& current > 0)
				{
					current--;
					clear(buffer);
					draw_circle(WIDTH / 2, HEIGHT / 2, radius, palettes[current], buffer);
				}

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
				{
					clear(buffer);
				}
				break;
			}
		}

		texture.update((sf::Uint8*) buffer);
		window.clear();
		window.draw(sprite);
		window.display();
	}

	delete [] buffer;
	return 0;
}
