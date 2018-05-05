#ifndef _H_ROCK
#define _H_ROCK

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <vector>
#include "global.h"
#include "GameObject.h"
#include "Ship.h"
#include "Output.h"

class Rock : public GameObject
{
	float m_rotateSpeed;
	float m_rotate;
	float m_deviation;

	bool m_isBroken;

	int m_type;
	float m_speed;
	SIZE m_size;

	float m_when_move_y;
	float m_when_move_x;
	float m_when_rotate;

	int m_direction;

	std::vector<Rock> m_dust;

public:
	Rock(COLOR, int deviation = 0);
	~Rock();

	void refresh();
	void bang();
	void draw(Output&);

	SIZE getSize() { return m_size; }
	int  getSpeed() { return m_speed; }
	bool isBroken() { return m_isBroken; }

private:
	void spawn();

};

#endif
