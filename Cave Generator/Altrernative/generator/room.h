#ifndef _H_ROOM
#define _H_ROOM

#include <vector>
#include "map.h"


enum RoomRelativePosition
{
	top_and_top_right,
	right_and_bottom_right,
	bottom_and_bottom_left,
	left_and_top_left
};


class Room : public Map
{
public:
	void operator=(const Room & other_room);

private:
	std::vector<Room*> children_;
	std::vector<LocalPoint> center_points_;
	GlobalPoint coords_;
	RoomRelativePosition master_relative_position_;

	friend class RoomGenerator;
};


#endif // !_H_ROOM
