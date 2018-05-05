// path.cpp
// the prototype of object that describes paths

#ifndef _H_PATH
#define _H_PATH

#include "headers.h"
#include "functions.h"

struct Point;


class Path
{
public:
	enum path_point { begin, end };

	void Draw(Point a, Point b);
	void AddPoint(Point x, unsigned position);
	void AddPoint(Point x, path_point position);
	void Write() const;

	inline Point GetPoint(int point) const;
	inline int GetLenght() const;
	inline void SetPoint(Point point, int index);

private:
	void Connect(Point a, Point b, bool add_point_a = true);

	std::vector<Point> path_;
};



inline Point Path::GetPoint(int point) const
{
	if (point < path_.size())
		return path_[point];
	else
	{
		ERROR("Index to the point in path is too large.\n"); // TODO: add exceptions
		return { 0, 0 };
	}
}

inline int Path::GetLenght() const
{
	return  path_.size();
}

inline void Path::SetPoint(Point point, int index)
{
	if (index >= GetLenght()); // TODO: Throw exception

	path_[index] = point;
}


#endif // _H_PATH
