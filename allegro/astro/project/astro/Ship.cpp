#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <random>
#include "Ship.h"

Ship::Ship(Output & output)
{
	m_isColored = false;
	recolor();
	m_x = PLAYER_SPAWN_X;
	m_y = PLAYER_SPAWN_Y;
	m_boundx = al_get_bitmap_width(output.getShip());
	m_boundy = al_get_bitmap_height(output.getShip());
}

void Ship::move(KEY key, bool boost)
{
	int move;
	if (!boost) move = PLAYER_BOOST_SPEED;
	else move = PLAYER_SPEED;

	if (key == UP)			m_y -= move;
	else if (key == DOWN)	m_y += move;
	else if (key == LEFT)	m_x -= move;
	else if (key == RIGHT)	m_x += move;
}

void Ship::recolor()
{
	std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<> range(0, 2);

	if (!m_isColored)
	{
		m_color = COLOR(range(generator));
		m_isColored = true;
	}
	else m_color = m_nextColor;

	do
		m_nextColor = COLOR(range(generator));
	while (m_nextColor == m_color);
}

void Ship::draw(Output & o)
{
	al_draw_tinted_bitmap(o.getShip(), o.getColor(m_color), m_x, m_y, 0);
}