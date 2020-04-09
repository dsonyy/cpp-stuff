// path.cpp
// the object that describes paths

#include <iostream>
#include "path.h"


void Path::Draw(Point a, Point b)
{
	path_.clear();
	Connect(a, b);
}


void Path::AddPoint(Point x)
{
	if (path_.size() == 0)
	{
		std::cerr << "Path is empty\n"; // TODO: make an exception
		return;
	}
	Connect(path_[path_.size() - 1], x, false);
}


void Path::Connect(Point a, Point b, bool add_point_a)
{

	Point cursor = a;


	if (add_point_a)
		path_.push_back(cursor);

	while (cursor.x != b.x || cursor.y != b.y)
	{
		int seed = rand() % 2;
		if (seed == 0 && cursor.x != b.x)
		{
			if (cursor.x > b.x) cursor.x--;
			else if (cursor.x < b.x) cursor.x++;
		}
		else
		{
			if (cursor.y > b.y)  cursor.y--;
			else if (cursor.y < b.y)  cursor.y++;
			else continue;
		}
		path_.push_back(cursor);
	}
}
