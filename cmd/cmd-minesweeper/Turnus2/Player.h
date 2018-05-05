#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include "Board.h"
#include "Coord.h"

class Player
{
public:
	Player();
	bool Move(Coord rel_positioin);

	int GetPosX() const { return position_.x; }
	int GetPosY() const { return position_.y; }

	void SetName(std::string new_name);
	void SetPosition(Coord new_position);

	void Kill()		{ alive_ = false;}
	void Born()		{ alive_ = true; }
	bool isAlive()	{ return alive_; }

private:
	Coord position_;
	std::string name_;
	bool alive_;
};

#endif