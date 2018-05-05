#ifndef _H_GAME
#define _H_GAME


#include "allegro-control.h"


class Game
{
public:
	Game();
	~Game();

	void Loop();
private:
	AllegroControl allegro;
	
	

};


#endif // !_H_GAME
