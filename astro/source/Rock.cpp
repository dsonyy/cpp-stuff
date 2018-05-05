#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <random>

#include "Rock.h"
#include "global.h"


#include <iostream>

Rock::Rock(COLOR color, int deviation)
{
	m_color = color;

	m_deviation = deviation;

	spawn();
}

Rock::~Rock() {}

void Rock::refresh()
{
	if (!m_isBroken)
	{
		m_when_move_y += m_speed;
		if (m_when_move_y > 1)
		{
			m_when_move_y -= 1.0;

			if (m_direction == 0) ++m_y;
			else				  --m_y;
		}

		m_when_rotate = 0;
		m_rotate += m_rotateSpeed;

		m_when_move_x += 0;
		if (int(m_when_move_x*100) % 100 > 0)
		{
			m_when_move_x -= 1.0;
			--m_x;
		}

		if		(m_direction == 0  &&  m_y > HEIGHT + m_boundy) spawn();
		else if (m_direction == 1  &&  m_y < 0 - m_boundy)		spawn();

	}
	else
	{
		for (int i = 0; i < MAX_DUST; ++i)
		{
			m_dust[i].refresh();

			if (m_dust[i].m_y < 0 - m_dust[i].m_boundy ||
				m_dust[i].m_y > HEIGHT + m_dust[i].m_boundy ||

				m_dust[i].m_x < 0 - m_dust[i].m_boundx ||
				m_dust[i].m_x > WIDTH + m_dust[i].m_boundx)
			{
				//spawn();
			}
		}
	}
}

void Rock::bang()
{
	m_isBroken = true;

	for (int i = 0; i < MAX_DUST; ++i)
	{
		m_dust.push_back(Rock(m_color, 250));

		m_dust[i].spawn();
		m_dust[i].m_size = SIZE(rand() % (m_size + 1));
		m_dust[i].m_x = m_x;
		m_dust[i].m_y = m_y;
	}

	/*
	if (m_size == BIG)
	{
		std::mt19937 generator(std::random_device{}());
		std::uniform_int_distribution<> dustGen(4, 7);
		std::uniform_int_distribution<> deviationGen(-3, 3);
		std::uniform_int_distribution<> sizeGen(0, 1);
		int maxDust = dustGen(generator);

		m_isBroken = true;
		for (int i = 0; i < maxDust; ++i)
		{
			m_dust.push_back(Rock(m_color, deviationGen(generator)));

			m_dust[i].spawn();
			m_dust[i].m_size = SIZE( sizeGen(generator) );
			m_dust[i].m_x = m_x;
			m_dust[i].m_y = m_y;
		}
	}
	else if (m_size == MEDIUM)
	{
		std::mt19937 generator(std::random_device{}());
		std::uniform_int_distribution<> deviationGen(-3, 3);
		int maxDust = 2;

		m_isBroken = true;
		for (int i = 0; i < maxDust; ++i)
		{
			m_dust.push_back(Rock(m_color, deviationGen(generator)));

			m_dust[i].spawn();
			m_dust[i].m_size = SMALL;
			m_dust[i].m_x = m_x;
			m_dust[i].m_y = m_y;
		}
	}
	else
	{
		std::mt19937 generator(std::random_device{}());
		std::uniform_int_distribution<> deviationGen(-3, 3);
		int maxDust = 1;

		m_isBroken = true;
		for (int i = 0; i < maxDust; ++i)
		{
			m_dust.push_back(Rock(m_color, deviationGen(generator)));

			m_dust[i].spawn();
			m_dust[i].m_size = SMALL;
			m_dust[i].m_x = m_x;
			m_dust[i].m_y = m_y;
		}
	}
	*/
}

void Rock::draw(Output & output)
{
	if ( ! m_isBroken )
	{
		m_boundx = al_get_bitmap_width(output.getRock(m_size, m_type));
		m_boundy = al_get_bitmap_height(output.getRock(m_size, m_type));

		al_draw_tinted_rotated_bitmap(output.getRock(m_size, m_type),
			output.getColor(m_color),
			m_boundx / 2, m_boundy / 2,
			m_x + m_boundx / 2, m_y + m_boundy / 2,
			m_rotate, NULL);
	}
	else
	{
		for (int i = 0; i < m_dust.size(); ++i)
		{
			m_dust[i].m_boundx = al_get_bitmap_width(output.getRock(m_dust[i].m_size, m_dust[i].m_type));
			m_dust[i].m_boundy = al_get_bitmap_height(output.getRock(m_dust[i].m_size, m_dust[i].m_type));

			al_draw_tinted_rotated_bitmap(output.getRock(m_dust[i].m_size, m_dust[i].m_type),
				output.getDeadColor(m_dust[i].m_color),
				m_dust[i].m_boundx / 2, m_dust[i].m_boundy / 2,
				m_dust[i].m_x + m_dust[i].m_boundx / 2, m_dust[i].m_y + m_dust[i].m_boundy / 2,
				m_dust[i].m_rotate, NULL);
		}
	}	

}

void Rock::spawn()
{
	m_when_move_x	= 0.0;
	m_when_move_y	= 0.0;
	m_when_rotate	= 0.0;
	m_size			= SIZE(rand() % USED_ROCK_SIZE);
	m_direction		= rand() % 2;
	m_speed			= float(rand() % MAX_ROCK_SPEED + 50) * 0.01;
	m_rotate		= 0.0;
	m_rotateSpeed	= float(rand() % 35 + 15) * 0.001;
	m_type			= rand() % USED_ROCK_TYPES;
	m_isBroken		= false;
	m_x				= rand() % (ROCKS_RIGHT_BOUND - ROCKS_LEFT_BOUND) + ROCKS_LEFT_BOUND;
	
	if (m_direction == 0) m_y = 0;//- (rand() % 150 + 50);
	else				 m_y = HEIGHT;// +(rand() % 150 + 50);

}

