#include <vector>
#include "room.h"

Room::Room()
{
	specimen_		= unspecifed;
	master_index_	= unspecifed;

	Point unspecifed_point = { unspecifed , unspecifed };
	coords_.corner[top_left] = unspecifed_point;
	coords_.corner[top_right] = unspecifed_point;
	coords_.corner[bottom_left] = unspecifed_point;
	coords_.corner[bottom_right] = unspecifed_point;
}

void Room::operator=(
	const Room & other_room)
{
	specimen_ = other_room.specimen_;
	block_array_ = other_room.block_array_;

	coords_ = other_room.coords_;
	center_points_ = other_room.center_points_;

	master_index_ = other_room.master_index_;
	childrens_indexes_ = other_room.childrens_indexes_;
}
