#ifndef _H_LEVEL_GENERATOR
#define _H_LEVEL_GENERATOR


#include "map.h"
#include "room.h"
#include "level.h"
#include "tunnel.h"


class LevelGenerator
{
public:
	LevelGenerator(RoomGenerator & room_gen, TunnelGenerator & tun_gen);
	Level Generate();

private:
	std::vector<Room> GenerateRoomsVector(size_t rooms_num);
	std::vector<Tunnel> GenerateTunnelsVector(const std::vector<Room> & rooms);

	bool		CheckAndSetRoomCoords(const std::vector<Room> & rooms, Room & room_to_place, Room & master) const;
	MapCoords	GenerateCoordsOnSide(const Room & master, RoomSide side_of_master, const Room & room_to_place) const;
	MapCoords	GenerateCoordsFromPoint(MapPoint point, CornerName point_corner, int width, int height) const;
	bool		CheckRoomCoords(const std::vector<Room> & rooms, const Room & room_to_check) const;
	bool		CheckCoords(const std::vector<Room> & rooms, const MapCoords & coords_to_check) const;
	void		PrintMap(const BlockMap & map, const MapCoords & coords, BlockMap & target) const;
	size_t		SetChildrenNum(size_t total_rooms_num, size_t completed_rooms_num, int queued_rooms_num) const;
	void		CheckAndPushNewRoom(size_t & next_room_index, std::vector<Room> & rooms, size_t & queued_rooms_num);
	void		SetOffsets(int & offset_x, int & offset_y, const std::vector<Room> & rooms) const;
	void		SetValidRoomsCoords(std::vector<Room> & rooms, int & offset_x, int & offset_y, int & width, int & height) const;
	void		GenerateEmptyBlockArray(Level & level, int width, int height) const;
	

	RoomGenerator	room_gen_;
	TunnelGenerator	tunnel_gen_;
	unsigned min_rooms_num_;
	unsigned max_rooms_num_;
	unsigned max_neighbors_num_;
	unsigned min_neighbors_num_;
	
};



#endif // !_H_LEVEL_GENERATOR
