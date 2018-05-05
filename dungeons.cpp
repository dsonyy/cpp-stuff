#include <vector>
#include <SFML/Graphics.hpp>

const unsigned int BUFFER_HEIGHT = 720;
const unsigned int BUFFER_WIDTH = 1280;

const unsigned int MAP_WIDTH = 20;
const unsigned int MAP_HEIGHT = 20;

int world_map[MAP_HEIGHT][MAP_WIDTH] = 
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};
sf::Vector2f player_pos(22, 12);
sf::Vector2f player_dir(-1, 0);
sf::Vector2f player_plane(0, 0.66);


sf::RenderWindow window;
sf::Color * buffer;
sf::Texture base_texture;
sf::Sprite base_sprite;

void update();
void render();

int main()
{
	window.create(sf::VideoMode(BUFFER_WIDTH, BUFFER_HEIGHT), "Dungeons", sf::Style::Close | sf::Style::Titlebar);
	buffer = new sf::Color[BUFFER_WIDTH * BUFFER_HEIGHT];
	base_texture.create(BUFFER_WIDTH, BUFFER_HEIGHT);
	base_sprite.setTexture(base_texture);
	
	sf::Clock clock;

	bool running = true;
	sf::Event event;
	sf::Time next_tick;

	while (running)
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				running = false;
				break;
			}
		}

		if (clock.getElapsedTime() >= next_tick)
		{
			update();
			render();

			next_tick += sf::milliseconds(1000 / 30);
		}
	}


	return 0;
}


void update()
{
	
}


void render()
{
	window.clear(sf::Color(128,128,255));
	window.draw(base_sprite);
	window.display();
}

