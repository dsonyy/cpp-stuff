#ifndef _H_ROOM_GENERATOR
#define _H_ROOM_GENERATOR


#include "map.h"
#include "room.h"
#include "path.h"


class RoomGenerator
{
public:
	RoomGenerator();
	const Room & Generate() const;

	inline int GetRoomEdgeSize()		const { return room_edge_; }
	inline int GetEffectiveRoomEdge()	const { return effective_room_edge_; }
	inline int GetMaxRectangleNumber()	const { return max_rectangles_num_; }
	inline int GetMinRectangleNumber()	const { return min_rectangles_num_; }
	inline int GetMaxRectangleEdge()	const { return max_rectangle_edge_; }
	inline int GetMinRectangleEdge()	const { return min_rectangle_edge_; }
	inline int GetMinOffset()			const { return min_offset_; }
	inline int GetMaxOffset()			const { return max_offset_; }
	inline int GetJerkProbability()		const { return jerk_probalility_; }

private:
	LocalPoint GenerateRectangle(Room & map, BlockType type = RoomFloor) const;
	void  JerkEdges(Room & map) const;
	void  RemoveLonePoints(Room & map) const;
	void  GeneratePaths(Room & map) const;
	void  BuildPathOnMap(Room & map, const Path & path, BlockType type = RoomFloor) const;

	int room_edge_;
	int effective_room_edge_;
	int max_rectangles_num_;
	int min_rectangles_num_;
	int max_rectangle_edge_;
	int min_rectangle_edge_;
	int min_offset_;
	int max_offset_;
	int jerk_probalility_;
};




#endif // _H_ROOM_GENERATOR