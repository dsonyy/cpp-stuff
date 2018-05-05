#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "Bullet.h"
#include "Output.h"
#include "global.h"

Bullet::Bullet(COLOR color, Output & output)
{
	sleep();
	m_color = color;
	m_miss = false;
	m_boundx = al_get_bitmap_width(output.getBullet());
	m_boundy = al_get_bitmap_height(output.getBullet());
}

void Bullet::sleep()
{
	m_x = 0;
	m_y = 0;
	m_live = false;
}

void Bullet::spawn(int x, int y, COLOR color)
{
	if (!m_live)
	{
		m_x = x;
		m_y = y;

 		m_color = color;
		m_live = true;
	}
}

void Bullet::refresh()
{
	if (m_live)
	{
		m_x -= BULLET_SPEED;
	}

	if (m_x + m_boundx < -m_boundx)
	{
		sleep();
		m_miss = true;
	}
}

void Bullet::draw(Output & o)
{
	if (m_live)
		al_draw_tinted_bitmap(o.getBullet(), o.getColor(m_color), m_x, m_y, 0);
}

bool Bullet::isMissed()
{
	if (m_miss == true)
	{
		m_miss = false;	
		return true;
	}
	else
		return false;
}
