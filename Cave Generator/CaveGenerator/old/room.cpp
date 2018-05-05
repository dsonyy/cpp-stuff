
#include <vector>
#include "room.h"


void Room::operator=(
	const Room & other_room)
{
	id_ = other_room.id_;
	map_ = other_room.map_;
	children_ = other_room.children_;
	coords_ = other_room.coords_;
	center_points_ = other_room.center_points_;
	master_relative_position_ = other_room.master_relative_position_;
}

