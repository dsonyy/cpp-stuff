#include "Res.h"

#include <vector>
#include "global.h"

namespace Res
{

	bool Res::loadRes()
	{
		
		ALLEGRO_BITMAP ** m_ship = new ALLEGRO_BITMAP*;
		ALLEGRO_BITMAP ** m_bullet = new ALLEGRO_BITMAP*;
		ALLEGRO_FONT ** m_font = new ALLEGRO_FONT*;
		ALLEGRO_BITMAP *** m_rock = new ALLEGRO_BITMAP**[USED_ROCK_SIZE];

		*m_ship = al_load_bitmap("images/ship");
		*m_bullet = al_load_bitmap("images/bullet");
		*m_font = al_create_builtin_font();
		for (int i = 0; i < USED_ROCK_SIZE; ++i)
		{
			m_rock[i] = new ALLEGRO_BITMAP*[USED_ROCK_TYPES];
			for (int j = 0; i < USED_ROCK_TYPES; ++j)
			{
				m_rock[i][j] = al_load_bitmap("images/rock" + i + j);
				if (!m_rock[i][j]) return false;
			}
		}

		if (! (m_ship && m_rock && m_font && m_bullet)) return false;
		else return true;
	}

	void deleteRes()
	{
		delete m_ship;
	}
}