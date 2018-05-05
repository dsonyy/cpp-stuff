#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include "allegro-control.h"


int main(int argc, char ** argv)
{
	char Room[5][5] 
	{
		{'#','#','#','#','#'},
		{'#','#','.','.','#'},
		{'#','.','.','.','#'},
		{'#','.','.','.','#'},
		{'#','#','#','#','#'}
	};

	AllegroControl allegro;
	allegro.Loop();

	return 0;
}