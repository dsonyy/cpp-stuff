#ifndef _H_LEVEL_GENERATOR
#define _H_LEVEL_GENERATOR


#include "level-generator.h"
#include "map.h"
#include "room.h"
#include "level.h"
#include "tunnel.h"


class LevelGenerator
{
public:
	enum LevelStructureSide
	{
		top_right,
		bottom_right,
		bottom_left,
		top_left,

		top,
		bottom,
		left,
		right,
		total_level_structure_sides
	};

	typedef LevelStructure Level;
	typedef LevelStructureEx Room;
	typedef LevelStructureEx Tunnel; //TODO: polimorfizm

	LevelGenerator();
	void Create(Level & target);

private:
	void GenerateTunnelContent(std::vector<Tunnel> & tunnels, Room const & room_start, Room const & room_end, TunnelGenerator const & tunnel_gen);

	void ShiftRoomsCoords(std::vector<Room> rooms);

	void DrawSpacialBlocksOnMap();
	void GenerateSpecialRegion(Point const & a, int max_radius_x, int max_radius_y, Block type);
	void DrawLevelStructureOnMap(Map2D & map, LevelStructure const & level_structure, Point coords);

	void GenerateChildRoomCoords(Point & valid_room_coords, std::vector<Room> const & rooms, Room const & master, int room_edge_size);
	bool CheckFreeSpaceForRoomCoords(std::vector<Room> const & rooms, Room const & master, int room_edge_size);
	bool CheckRoomCoords(Point const & child_room_coords, std::vector<Room> const & rooms, int room_edge_size);

	
	unsigned min_rooms_num_;
	unsigned max_rooms_num_;
	unsigned max_neighbors_num_;
	unsigned min_neighbors_num_;
};



#endif // _H_LEVEL_GENERATOR
