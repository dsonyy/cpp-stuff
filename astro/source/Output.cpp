#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>
#include "Output.h"

#include <iostream>

Output::Output()
{
	m_ship	= al_load_bitmap("images/ship.png");
	check(m_ship);

	m_rock[SMALL][0] = al_load_bitmap("images/small0.png");
	m_rock[SMALL][1] = al_load_bitmap("images/small1.png");
	m_rock[SMALL][2] = al_load_bitmap("images/small2.png");
	m_rock[SMALL][3] = al_load_bitmap("images/small3.png");
	m_rock[SMALL][4] = al_load_bitmap("images/small4.png");

	m_rock[MEDIUM][0] = al_load_bitmap("images/medium0.png");
	m_rock[MEDIUM][1] = al_load_bitmap("images/medium1.png");
	m_rock[MEDIUM][2] = al_load_bitmap("images/medium2.png");
	m_rock[MEDIUM][3] = al_load_bitmap("images/medium3.png");
	m_rock[MEDIUM][4] = al_load_bitmap("images/medium4.png");

	m_rock[BIG][0] = al_load_bitmap("images/big0.png");
	m_rock[BIG][1] = al_load_bitmap("images/big1.png");
	m_rock[BIG][2] = al_load_bitmap("images/big2.png");
	m_rock[BIG][3] = al_load_bitmap("images/big3.png");
	m_rock[BIG][4] = al_load_bitmap("images/big4.png");
	for (int i = 0; i < USED_ROCK_SIZE; ++i)
		for (int j = 0; j < USED_ROCK_TYPES; ++j)
			check(m_rock[i][j]);

	m_bullet = al_load_bitmap("images/bullet.png");
	check(m_bullet);

	m_font = al_create_builtin_font();
	check(m_font);

}

Output::~Output()
{
	al_destroy_bitmap( m_ship );
	al_destroy_bitmap( m_bullet );
	for (int i = 0; i < USED_ROCK_SIZE; ++i)
		for (int j = 0; j < USED_ROCK_TYPES; ++j)
			al_destroy_bitmap( m_rock[i][j] );
	al_destroy_font(m_font);
}

template <class T> bool Output::check(T type)
{
	if (!type)
	{
		al_show_native_message_box(al_get_current_display(), "Game", "Fatal error:",
			"Failed to load game resources!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return false;
	}
	return true;
}
