#include <vector>
#include "console.h"
#include "map.h"


void Map::Write() const
{
	if (specimen_ >= 0)
	{
		info << "Specimen " << specimen_ << "\n";
	}
	else
	{
		info << "\n";
	}

	for (size_t y = 0; y < block_array_.size(); y++)
	{
		info << "";
		for (size_t x = 0; x < block_array_[y].size(); x++)
		{
			std::cout.put(block_array_[y][x]);
		}
		std::cout << std::endl;
	}
}