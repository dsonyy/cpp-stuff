// path.cpp
// the prototype of object that describes paths

#include "console.h"
#include "map.h"

#ifndef _H_PATH
#define _H_PATH

class Path
{
public:
	void Draw(Point a, Point b);
	void AddPoint(Point x);

	inline Point GetPoint(size_t point) const;
	inline Point GetLastPoint() const;
	inline int GetLenght() const;
	inline void SetPoint(Point point, int index);

private:
	void Connect(Point a, Point b, bool add_point_a = true);

	std::vector<Point> path_;
};



inline Point Path::GetPoint(size_t point) const
{
	if (point < path_.size())
	{
		return path_[point];
	}
	else
	{
		error << "Index to the point in path is too large.\n"; // TODO: add exceptions
		return { 0, 0 };
	}
}

inline Point Path::GetLastPoint() const
{
	return path_[path_.size() - 1];
}

inline int Path::GetLenght() const
{
	return path_.size();
}

inline void Path::SetPoint(Point point, int index)
{
	if (index >= GetLenght())
	{
		// TODO: Throw exception
	}

	path_[index] = point;
}


#endif // !_H_PATH