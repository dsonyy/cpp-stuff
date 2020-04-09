#ifndef _H_LOGIC
#define _H_LOGIC
#include <vector>
#include "Ship.h"
#include "global.h"
#include "Rock.h"
#include "Output.h"
#include "Bullet.h"

class Logic
{
	Output m_output;
	std::vector<Ship> m_player;
	std::vector<Rock> m_rock;
	std::vector<Bullet> m_bullet;
	bool m_key[USED_KEYS];
	int m_points;
	int m_time;

public:
	Logic();

	void setKey(KEY key, bool down) { m_key[key] = down; };
	void refresh();
	void draw();
	void point(Rock, Bullet);

	void addTime(int time) { m_time += time; }
	int  getTime() { return m_time; }
};

#endif