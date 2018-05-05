// room.h -- 
#pragma once
#include "minerals.h"
 


class Room
{
public:
	struct Type
	{
		double difficulty = 1.0;

	};

	Room();
	Room(const Type & type);
	~Room();



private:
	Type type_;
	MineralsContainer minerals_;

};

