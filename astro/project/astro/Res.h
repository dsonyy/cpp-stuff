#ifndef _H_RES
#define _H_RES

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include "global.h"

namespace Res
{
	bool loadRes();
	void deleteRes();

	ALLEGRO_BITMAP * getShipBitmap();
	ALLEGRO_BITMAP * getRockBitmap(SIZE, int);
	ALLEGRO_BITMAP * getBulletBitmap();
	ALLEGRO_FONT   * getFont();
	ALLEGRO_COLOR  * getColor(COLOR);
	ALLEGRO_COLOR  * getDeadColor(COLOR);

}

#endif
