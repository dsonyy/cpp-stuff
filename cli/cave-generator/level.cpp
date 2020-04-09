#include "level.h"

void Level::operator=(const Level & other_level)
{
	rooms_area_ = other_level.rooms_area_;
	tunnels_area_ = other_level.tunnels_area_;
	
	specimen_ = other_level.specimen_;
	block_array_ = other_level.block_array_;
}