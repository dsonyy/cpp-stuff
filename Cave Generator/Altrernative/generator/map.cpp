// map.cpp


#include <vector>
#include "functions.h"
#include "map.h"


void Map::Write(ID id) const
{
	if (id.specimen >= 0)
	{
		INFO("Seed %i, Specimen %i\n", id.seed, id.specimen);
	}

	for (int y = 0; y < map_.size(); y++)
	{
		INFO("");
		for (int x = 0; x < map_[y].size(); x++)
		{
			putchar(map_[y][x]);
		}
		printf("\n");
	}
}
