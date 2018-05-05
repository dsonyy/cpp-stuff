#include <vector>
#include "console.h"
#include "map.h"
#include "level-gen.h"
#include "room-gen.h"
#include "tunnel-gen.h"

LevelGenerator::LevelGenerator(RoomGenerator & room_gen, TunnelGenerator & tun_gen)
{
	info << "Initializing level generator components\n";
	min_rooms_num_ = 100;
	max_rooms_num_ = 100;

	room_gen_ = room_gen;
	tunnel_gen_ = tun_gen;

	min_neighbors_num_ = 1;
	max_neighbors_num_ = 4;
}

Level LevelGenerator::Generate()
{
	Level level;
	size_t rooms_num = rand() % (max_rooms_num_ - min_rooms_num_ + 1) + min_rooms_num_;
	std::vector<Room> rooms = GenerateRoomsVector(rooms_num);

	int offset_x = 0, offset_y = 0;
	SetOffsets(offset_x, offset_y, rooms);

	int width = 0, height = 0;
	SetValidRoomsCoords(rooms, offset_x, offset_y, width, height);

	GenerateEmptyBlockArray(level, width, height);

	std::vector<Tunnel> tunnels = GenerateTunnelsVector(rooms);

	for (size_t i = 0; i < rooms.size(); ++i)
	{
		PrintMap(rooms[i].GetBlockArray(), rooms[i].GetCoords(), level.block_array_);
	}

	for (size_t i = 0; i < tunnels.size(); ++i)
	{
		PrintMap(tunnels[i].GetBlockArray(), tunnels[i].GetCoords(), level.block_array_);
	}

	return level;
}

bool LevelGenerator::CheckRoomCoords(
	const std::vector<Room> & rooms,
	const Room & room_to_check) const
{

	for (int i = 0; i < rooms.size(); ++i)
	{
		for (int j = 0; j < total_corners; ++j)
		{
			if (room_to_check.GetCoords().corner[j].x >= rooms[i].GetCoords().corner[top_left].x &&
				room_to_check.GetCoords().corner[j].x <= rooms[i].GetCoords().corner[bottom_right].x &&
				room_to_check.GetCoords().corner[j].y >= rooms[i].GetCoords().corner[top_left].y &&
				room_to_check.GetCoords().corner[j].y <= rooms[i].GetCoords().corner[bottom_right].y)
			{
				return false;
			}
		}
	}

	return true;
}

bool LevelGenerator::CheckCoords(
	const std::vector<Room> & rooms,
	const MapCoords & coords_to_check) const
{

	for (int i = 0; i < rooms.size(); ++i)
	{
		for (int j = 0; j < total_corners; ++j)
		{
			if (coords_to_check.corner[j].x >= rooms[i].GetCoords().corner[top_left].x &&
				coords_to_check.corner[j].x <= rooms[i].GetCoords().corner[bottom_right].x &&
				coords_to_check.corner[j].y >= rooms[i].GetCoords().corner[top_left].y &&
				coords_to_check.corner[j].y <= rooms[i].GetCoords().corner[bottom_right].y)
			{
				return false;
			}
		}
	}

	return true;
}

MapCoords LevelGenerator::GenerateCoordsOnSide(
	const Room & master, 
	RoomSide side_of_master,
	const Room & room_to_place) const
{
	MapCoords temp;

	switch (side_of_master)
	{
	case top_and_top_right:
		temp.corner[top_left] = {
			master.GetCoords().corner[top_left].x + rand() % (room_to_place.GetWidth() + 1),
			master.GetCoords().corner[top_left].y - room_to_place.GetHeight(),
		};
		break;
	case right_and_bottom_right:
		temp.corner[top_left] = {
			master.GetCoords().corner[top_left].x + room_to_place.GetWidth(),
			master.GetCoords().corner[top_left].y + rand() % (room_to_place.GetHeight() + 1),
		};
		break;
	case bottom_and_bottom_left:
		temp.corner[top_left] = {
			master.GetCoords().corner[top_left].x - rand() % (room_to_place.GetWidth() + 1),
			master.GetCoords().corner[top_left].y + room_to_place.GetHeight(),
		};
		break;
	case left_and_top_left:
		temp.corner[top_left] = {
			master.GetCoords().corner[top_left].x - room_to_place.GetWidth(),
			master.GetCoords().corner[top_left].y - rand() % (room_to_place.GetHeight() + 1),
		};
		break;
	}

	return GenerateCoordsFromPoint(
		temp.corner[top_left],
		top_left, 
		room_to_place.GetWidth(), 
		room_to_place.GetHeight());
}

bool LevelGenerator::CheckAndSetRoomCoords(
	const std::vector<Room> & rooms,
	Room & room_to_place,
	Room & master) const
{
	bool		excluded_room_sides[total_room_sides] = { false, false, false, false};
	RoomSide	sides_counter = RoomSide(rand() % total_room_sides);
	size_t		iterator = 0;
	
	while (iterator < total_room_sides)
	{
		MapCoords coords_to_check = GenerateCoordsOnSide(master, sides_counter, room_to_place);
		if (CheckCoords(rooms, coords_to_check))
		{
			room_to_place.SetCoords(coords_to_check);
			return true;
		}

		sides_counter = RoomSide((sides_counter + 1) % total_room_sides);
		++iterator;
	}

	return false;
}

void LevelGenerator::PrintMap(
	const BlockMap & map,
	const MapCoords & coords,
	BlockMap & target) const
{
	for (size_t y = 0; y < map.size() && coords.corner[top_left].y + y < target.size(); ++y)
	{
		for (size_t x = 0; x < map[y].size() && coords.corner[top_left].x + x < target[y].size(); ++x)
		{
			if (map[y][x] != None)
			{
				target[coords.corner[top_left].y + y]
					[coords.corner[top_left].x + x] =
					map[y][x];
			}
		}
	}
}

size_t LevelGenerator::SetChildrenNum(
	size_t total_rooms_num,
	size_t completed_rooms_num,
	int queued_rooms_num) const
{
	if (total_rooms_num - completed_rooms_num + queued_rooms_num <= max_neighbors_num_)
	{
		return total_rooms_num - completed_rooms_num + queued_rooms_num;
	}
	else
	{
		return size_t(rand() % (max_neighbors_num_ - min_neighbors_num_ + 1) + min_neighbors_num_);
	}
}

void LevelGenerator::CheckAndPushNewRoom(
	size_t & next_room_index,
	std::vector<Room> & rooms,
	size_t & queued_rooms_num)
{
	if (next_room_index == rooms.size())
	{
		rooms.push_back(room_gen_.Generate());
		++next_room_index;
		++queued_rooms_num;
	}
}

std::vector<Room> LevelGenerator::GenerateRoomsVector(
	size_t rooms_num)
{
	std::vector<Room> rooms;
	size_t master_index = 0;
	size_t next_child_index = 1;
	size_t finished_index = 0;
	size_t queued = 0;

	rooms.push_back(room_gen_.Generate());

	while (rooms.size() < rooms_num || queued != 0)
	{
		size_t children_num = SetChildrenNum(rooms_num, rooms.size(), queued);

		for (int i = 0; i < children_num; ++i)
		{
			if (master_index > 0 && rooms[next_child_index - 1].GetMasterIndex() == Room::unspecifed)
			{
				if (CheckAndSetRoomCoords(rooms, rooms[next_child_index - 1], rooms[master_index]))
				{
					rooms[master_index].AddChildIndex(next_child_index - 1);
					rooms[next_child_index - 1].SetMasterIndex(master_index);
					--queued;
				}

				break;
			}
			CheckAndPushNewRoom(next_child_index, rooms, queued);
			if (CheckAndSetRoomCoords(rooms, rooms[next_child_index - 1], rooms[master_index]))
			{
				rooms[master_index].AddChildIndex(next_child_index - 1);
				rooms[next_child_index - 1].SetMasterIndex(master_index);
				--queued;
			}
			else
			{
				break;
			}
		}

		++master_index;
	}

	return rooms;
}

void LevelGenerator::SetOffsets(
	int & offset_x,
	int & offset_y,
	const std::vector<Room> & rooms) const
{
	for (size_t i = 0; i < rooms.size(); ++i)
	{
		if (rooms[i].GetCoords().corner[top_left].x < offset_x)
		{
			offset_x = rooms[i].GetCoords().corner[top_left].x;
		}

		if (rooms[i].GetCoords().corner[top_left].y < offset_y)
		{
			offset_y = rooms[i].GetCoords().corner[top_left].y;
		}
	}
}

void LevelGenerator::SetValidRoomsCoords(
	std::vector<Room> & rooms,
	int & offset_x,
	int & offset_y,
	int & width,
	int & height) const
{

	for (size_t i = 0; i < rooms.size(); ++i)
	{
		MapCoords temp;

		temp.corner[top_left] = {
			rooms[i].GetCoords().corner[top_left].x - offset_x,
			rooms[i].GetCoords().corner[top_left].y - offset_y
		};

		temp = GenerateCoordsFromPoint(
			temp.corner[top_left], 
			top_left, 
			rooms[i].GetWidth(), 
			rooms[i].GetHeight()
		);

		if (temp.corner[bottom_right].x > width)
		{
			width = temp.corner[bottom_right].x + 1;
		}
		if (temp.corner[bottom_right].y > height)
		{
			height = temp.corner[bottom_right].y + 1;
		}

		rooms[i].SetCoords(temp);
	}
}

void LevelGenerator::GenerateEmptyBlockArray(
	Level & level,
	int width,
	int height) const
{
	level.block_array_.resize(height);
	for (int y = 0; y < height; ++y)
	{
		level.block_array_[y].resize(width);
		for (int x = 0; x < width; ++x)
		{
			level.block_array_[y][x] = Wall;
		}
	}
}

std::vector<Tunnel> LevelGenerator::GenerateTunnelsVector(
	const std::vector<Room> & rooms)
{
	std::vector<Tunnel> tunnels;

	for (size_t i = 1; i < rooms.size(); ++i)
	{
		Point a = rooms[rooms[i].GetMasterIndex()].GetRandomCenterPoint();
		a.x += rooms[rooms[i].GetMasterIndex()].GetCoords().corner[top_left].x;
		a.y += rooms[rooms[i].GetMasterIndex()].GetCoords().corner[top_left].y;

		Point b = rooms[i].GetRandomCenterPoint();
		b.x += rooms[i].GetCoords().corner[top_left].x;
		b.y += rooms[i].GetCoords().corner[top_left].y;

		tunnels.push_back(tunnel_gen_.Generate(a, b));
	}

	return tunnels;
}

MapCoords LevelGenerator::GenerateCoordsFromPoint(
	MapPoint point, 
	CornerName point_corner,
	int width,
	int height) const
{
	MapCoords temp;
	width -= 1;
	height -= 1;

	switch (point_corner)
	{
	case top_left:
		temp.corner[top_left]		= point;
		temp.corner[top_right]		= { point.x + width, point.y };
		temp.corner[bottom_left]	= { point.x, point.y + height };
		temp.corner[bottom_right]	= { point.x + width, point.y + height };
		break;
	case top_right:
		temp.corner[top_left]		= { point.x - width, point.y };
		temp.corner[top_right]		= point;
		temp.corner[bottom_left]	= { point.x - width, point.y - height};
		temp.corner[bottom_right]	= { point.x, point.y + height};
		break;
	case bottom_left:
		temp.corner[top_left]		= { point.x, point.y - height};
		temp.corner[top_right]		= { point.x + width, point.y - height};
		temp.corner[bottom_left]	= point;
		temp.corner[bottom_right]	= { point.x + width, point.y };
		break;
	case bottom_right:
		temp.corner[top_left]		= { point.x - width, point.y - height};
		temp.corner[top_right]		= { point.x, point.y - height};
		temp.corner[bottom_left]	= { point.x - width, point.y };
		temp.corner[bottom_right]	= point;
		break;
	}

	return temp;
}
