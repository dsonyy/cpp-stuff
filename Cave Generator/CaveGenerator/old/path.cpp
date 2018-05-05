// path.cpp
// the object that describes paths

#include "path.h"
#include "headers.h"
#include "functions.h"



void Path::Draw(Point a, Point b)
{
	path_.clear();
	Connect(a,b);
}

void Path::AddPoint(Point x, unsigned start_point)
{
	if (path_.size() == 0)
	{
		ERROR("Path is empty.\n"); // TODO: make an exception
		return;
	}

	if (start_point > path_.size() - 1)
		start_point = path_.size() - 1;

	Connect(path_[start_point], x, false);
}

void Path::AddPoint(Point x, path_point position)
{
	if (position == end)
		AddPoint(x, path_.size());
	else
		AddPoint(x, 0);
}

void Path::Write() const
{
	INFO("********************************\n");
	for (int i = 0; i < path_.size(); i++)
		INFO("Point %i (%i, %i)\n", i + 1, path_[i].x, path_[i].y);
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
