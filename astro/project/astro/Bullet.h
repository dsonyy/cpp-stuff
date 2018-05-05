#ifndef _H_BULLET
#define _H_BULLET

#include "GameObject.h"
#include "Output.h"
#include "global.h"

class Bullet
	: public GameObject
{
	bool m_live;
	bool m_miss;

public:
	Bullet(COLOR, Output&);

	void sleep();
	void spawn(int, int, COLOR);
	void refresh();
	void draw(Output&);

	void setLive(bool live) { m_live = live; }

	bool isLive() { return m_live; }
	bool isMissed();

};

#endif
