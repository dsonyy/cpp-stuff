#ifndef _H_ROOM
#define _H_ROOM

#include <vector>
#include "map.h"


enum RoomSide
{
	top_and_top_right,
	right_and_bottom_right,
	bottom_and_bottom_left,
	left_and_top_left,

	total_room_sides
};



class Room : public Map
{
public:
	enum : size_t { unspecifed = -1};

	Room();
	void operator=(const Room & other_room);

	inline const std::vector<MapPoint> &	GetCenterPoints() const;
	inline MapPoint							GetCenterPoint(size_t index) const;
	inline size_t							GetCenterPointsNum() const;
	inline MapPoint							GetRandomCenterPoint() const;
	inline void								SetCenterPoints(const std::vector<MapPoint> & other_center_points);
	inline void								AddCenterPoint(const MapPoint & other_center_point);
	inline const LevelCoords &				GetCoords() const;
	inline void								SetCoords(const LevelCoords & other_coords);
	inline const std::vector<size_t> &		GetChildrenIndexes() const;
	inline void								AddChildIndex(size_t other_index);
	inline size_t							GetMasterIndex() const;
	inline void								SetMasterIndex(size_t other_index);

private:
	std::vector<MapPoint>		center_points_;
	LevelCoords					coords_;
	size_t						master_index_;
	std::vector<size_t>			childrens_indexes_;

	friend class RoomGenerator;
};



//============================= CENTER POINTS =============================
inline const std::vector<MapPoint> & Room::GetCenterPoints() const
{
	return center_points_;
}
inline MapPoint	Room::GetCenterPoint(size_t index) const
{
	if (index < 0 && index >= center_points_.size()); // TODO: throw an exception

	return center_points_[index];
}

inline size_t Room::GetCenterPointsNum() const
{
	return center_points_.size();
}

inline MapPoint Room::GetRandomCenterPoint() const
{
	return center_points_[rand() % center_points_.size()];
}


inline void	Room::SetCenterPoints(const std::vector<MapPoint> & other_center_points)
{
	center_points_ = other_center_points;
}
inline void	Room::AddCenterPoint(const MapPoint & other_center_point)
{
	center_points_.push_back(other_center_point);
}

//================================ COORDS =================================
inline const LevelCoords & Room::GetCoords() const
{
	return coords_;
}
inline void	Room::SetCoords(const LevelCoords & other_coords)
{
	coords_ = other_coords;
}

//=============================== CHILDREN ================================
inline const std::vector<size_t> & Room::GetChildrenIndexes() const
{
	return childrens_indexes_;
}

inline void	Room::AddChildIndex(size_t other_index)
{
	childrens_indexes_.push_back(other_index);
}
//=============================== MASTER ==================================
inline size_t Room::GetMasterIndex() const
{
	return master_index_;
}

inline void	Room::SetMasterIndex(size_t other_index)
{
	master_index_ = other_index;
}

#endif // !_H_ROOM
