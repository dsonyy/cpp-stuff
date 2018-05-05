#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_primitives.h>


#include "Logic.h"
#include "Ship.h"
#include "Rock.h"
#include <iostream>

Logic::Logic()
{
	m_player.push_back(Ship(m_output));

	for (int i = 0, c = 0; i < MAX_ROCKS; ++i)
	{
		m_rock.push_back(Rock(COLOR(c++)));
		if (c == USED_COLORS) c = 0;
	}

	for (int i = 0; i < MAX_BULLET; ++i)
	{
		Bullet bullet(m_player[0].getColor(), m_output);
		m_bullet.push_back(bullet);
	}

	for (int i = 0; i < USED_KEYS; ++i)
		m_key[i] = false;

	m_points = 0;
	m_time = GAME_TIME;
}

void Logic::refresh()
{
	if (m_key[UP] && m_player[0].getY0() > 0)					 m_player[0].move(UP, m_key[Z]);
	if (m_key[DOWN] && m_player[0].getY1() < HEIGHT)			 m_player[0].move(DOWN, m_key[Z]);
	if (m_key[LEFT] && m_player[0].getX0() > PLAYER_LEFT_BOUND)	 m_player[0].move(LEFT, m_key[Z]);
	if (m_key[RIGHT] && m_player[0].getX1() < PLAYER_RIGHT_BOUND)m_player[0].move(RIGHT, m_key[Z]);
	if (m_key[SPACE])
	{
		for (int i = 0; i < MAX_BULLET; ++ i)
		{
			if (!m_bullet[i].isLive())
			{
				m_bullet[i].spawn(m_player[0].getX0() + m_player[0].getBoundX() / 2,
								  m_player[0].getY0() + m_player[0].getBoundY() / 2 - m_bullet[i].getBoundY() / 2,
								  m_player[0].getColor() );
				break;
			}
		}
		m_key[SPACE] = false;
	}

	for (int i = 0; i < MAX_ROCKS; ++ i)
		m_rock[i].refresh();

	for (int i = 0; i < MAX_BULLET; ++i)
	{
		m_bullet[i].refresh();
		for (int j = 0; j < MAX_ROCKS; ++j)
		{
			if ( int(m_bullet[i].getColor()) == int(m_rock[j].getColor()) &&
					 !m_rock[j].isBroken() &&
					 m_rock[j].getX0() <= m_bullet[i].getX0() &&
					 m_rock[j].getX1() >= m_bullet[i].getX0() &&
					 m_rock[j].getY0() <= m_bullet[i].getY0() &&
					 m_rock[j].getY1() >= m_bullet[i].getY0() )
			{
				m_bullet[i].sleep();
				m_rock[j].bang();
				m_player[0].recolor();
				
				point(m_rock[j], m_bullet[i]);
			}
		}
	}
}

void Logic::draw()
{
	for (int i = 0; i < MAX_ROCKS; ++i)
		m_rock[i].draw(m_output);

	for (int i = 0; i < MAX_BULLET; ++i)
		m_bullet[i].draw(m_output);

	m_player[0].draw(m_output);

	al_draw_textf(m_output.getFont(), al_map_rgb(255, 255, 255), 10, 10, 0,
		"SCORE: %i", m_points);
	al_draw_textf(m_output.getFont(), al_map_rgb(255, 255, 255), 10, 25, 0,
		"TIME:  %i", m_time);
	
	if (m_time == 0)
	{
		al_draw_text(m_output.getFont(), al_map_rgb(255, 255, 255),
			WIDTH / 2, HEIGHT / 2 - 15, ALLEGRO_ALIGN_CENTER,
			"GAME OVER");
		al_draw_text(m_output.getFont(), al_map_rgb(255, 255, 255),
			WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTER,
			"Thanks for playing :D");
		al_draw_text(m_output.getFont(), al_map_rgb(255, 255, 255),
			WIDTH / 2, HEIGHT / 2 + 10, ALLEGRO_ALIGN_CENTER,
			"Check out my git: github.com/dsony");
	}
}

void Logic::point(Rock r, Bullet b)
{
	if		(r.getSize() == BIG)	m_points += POINTS_HIT_2;
	else if (r.getSize() == MEDIUM)	m_points += POINTS_HIT_1;
	else
	{
		m_points += POINTS_HIT_0;
		m_time += TIME_BONUS;
	}

	if		(r.getSpeed() < MAX_ROCK_SPEED / 3.0)		m_points += POINTS_HIT_2;
	else if (r.getSpeed() < MAX_ROCK_SPEED / 3.0 * 2.0) m_points += POINTS_HIT_1;
	else												m_points += POINTS_HIT_0;
	
	m_points += m_player[0].getX0() /
		((PLAYER_RIGHT_BOUND - PLAYER_LEFT_BOUND) / POINTS_HIT_0);

	if (b.isMissed()) m_points -= POINTS_HIT_2;
}