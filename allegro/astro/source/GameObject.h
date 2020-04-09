#ifndef _H_GAME_OBJECT
#define _H_GAME_OBJECT

#include "global.h"

class GameObject
{
protected:
	int		m_x;
	int		m_y;
	int		m_boundx;
	int		m_boundy;
	COLOR	m_color;

public:
	int		getX0()		{ return m_x; }
	int		getY0()		{ return m_y; }
	int		getX1()		{ return m_x + m_boundx; }
	int		getY1()		{ return m_y + m_boundy; }
	int		getBoundX() { return m_boundx; }
	int		getBoundY() { return m_boundy; }
	COLOR	getColor()	{ return m_color; };
};

#endif
