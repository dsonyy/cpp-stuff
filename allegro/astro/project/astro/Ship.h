#ifndef _H_SHIP
#define _H_SHIP

#include "global.h"
#include "GameObject.h"
#include "Output.h"

class Ship : public GameObject
{
	COLOR m_nextColor;
	bool m_isColored;

public:
	Ship(Output&);
	
	void move(KEY, bool);
	void recolor();
	void draw(Output&);

};


#endif