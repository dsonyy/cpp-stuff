#ifndef _H_BITMAP_BOX
#define _H_BITMAP_BOX

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include "global.h"

class Output
{
	ALLEGRO_BITMAP * m_ship;
	ALLEGRO_BITMAP * m_rock[USED_ROCK_SIZE][USED_ROCK_TYPES];
	ALLEGRO_BITMAP * m_bullet;
	ALLEGRO_FONT * m_font;

public:
	Output();
	~Output();

	ALLEGRO_BITMAP* getShip()				{ return m_ship; }
	ALLEGRO_BITMAP* getRock(SIZE s, int t)	{ return m_rock[s][t]; }
	ALLEGRO_BITMAP* getBullet()				{ return m_bullet; }
	ALLEGRO_COLOR	getColor(COLOR c)		{ return GAME_COLOR[c]; }
	ALLEGRO_COLOR	getDeadColor(COLOR c)	{ return GAME_COLOR2[c]; }
	ALLEGRO_FONT*	getFont()				{ return m_font; }

private:
	template <class T> bool check(T);

};


#endif