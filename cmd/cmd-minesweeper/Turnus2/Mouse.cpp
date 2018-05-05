#include <allegro5\allegro.h>
#include "Coord.h"

#include "Mouse.h"

Mouse::Mouse()
{
	al_install_mouse();
}

Mouse::~Mouse()
{
	al_uninstall_mouse();
}

Coord GetPosition()
{
	Coord pos = { 0,0 };

	return pos;
}
