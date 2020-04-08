#include <iostream>
#include <vector>
#include "map.h"


void Map::Write() const
{

	for (size_t y = 0; y < block_array_.size(); y++)
	{
		for (size_t x = 0; x < block_array_[y].size(); x++)
		{
			std::cout.put(block_array_[y][x]);
		}
		std::cout << std::endl;
	}
}