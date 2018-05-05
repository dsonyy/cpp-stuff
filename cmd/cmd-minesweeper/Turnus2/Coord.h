#pragma once

struct Coord
{
	int x;
	int y;

	bool operator==(Coord other_coord)
	{
		if (other_coord.x == x && other_coord.y == y)
		{
			return true;
		}

		return false;
	}
};