

#include "headers.h"
#include "functions.h"
#include "room-generator.h"
#include "tunnel-generator.h"
#include "level-generator.h"

LevelGenerator::LevelGenerator()
{
	// TODO: initialization all variables 

	min_rooms_num_ = 25;
	max_rooms_num_ = 25;

	min_neighbors_num_ = 1;
	max_neighbors_num_ = 4;

	// TODO: check vaiables
}


void LevelGenerator::GenerateTunnelContent(
	std::vector<Tunnel> & tunnels,
	Room const & room_a,
	Room const & room_b,
	TunnelGenerator const & tunnel_gen)
{
	Tunnel temp;
	Point room_a_door = room_a.content.GetDoor(rand() % room_a.content.GetDoorsNumber());
	Point room_b_door;

	int count = 0;
	do
	{
		room_b_door = room_b.content.GetDoor(count);
		++count;
	} while ((room_a_door.x == room_b_door.x && room_a_door.y != room_b_door.y) &&
		count < room_b.content.GetDoorsNumber());

	tunnel_gen.Create(temp.content, room_a_door, room_b_door);
	tunnels.push_back(temp);
}

void LevelGenerator::ShiftRoomsCoords(std::vector<Room> rooms)
{

}



void LevelGenerator::Create(
	Level & target)
{
	int					rooms_num = rand() % (max_rooms_num_ - min_rooms_num_ + 1) + min_rooms_num_;
	Map2D				map;
	RoomGenerator		room_gen;
	TunnelGenerator		tunnel_gen;
	std::vector<Room>	rooms;
	std::vector<Tunnel>	tunnels;
	Point				map_begin = { 0,0 };
	Point				map_end = { room_gen.GetRoomEdgeSize(), room_gen.GetRoomEdgeSize() };
	int width = 200;
	int height = 200;
	
	Room master;
	room_gen.Create(master.content);
	master.coords = map_begin;
	rooms.push_back(master);

	int count = 0;
	while (rooms_num > rooms.size())
	{
		master = rooms[count];

		int neighbors;
		if (rooms_num - rooms.size() <= max_neighbors_num_) neighbors = rooms_num - rooms.size();
		else neighbors = rand() % (max_neighbors_num_ - min_neighbors_num_ + 1) + min_neighbors_num_;

		for (int i = 0; i < neighbors; i++)
		{
			if (CheckFreeSpaceForRoomCoords(rooms, master, room_gen.GetRoomEdgeSize()))
			{
				Room child;
				room_gen.Create(child.content);
				GenerateChildRoomCoords(child.coords, rooms, master, room_gen.GetRoomEdgeSize());
				rooms.push_back(child);


				Tunnel tunnel;
				Point master_door = master.content.GetDoor(rand() % master.content.GetDoorsNumber());
				Point child_door = child.content.GetDoor(rand() % child.content.GetDoorsNumber());

				Point master_door_absolute = {
					master.coords.x + master_door.x,
					master.coords.y + master_door.y
				};
				Point child_door_absolute = {
					child.coords.x + child_door.x,
					child.coords.y + child_door.y
				};

				tunnel_gen.Create(tunnel.content, master_door_absolute, child_door_absolute);
				tunnel.coords = {
					(master_door_absolute.x < child_door_absolute.x ? master_door_absolute.x : child_door_absolute.x),
					(master_door_absolute.y < child_door_absolute.y ? master_door_absolute.y : child_door_absolute.y)
				};
				tunnels.push_back(tunnel);
			}
			else
			{
				break;
			}
		}
		count++;
	}

	map_begin.x += rooms[0].coords.x;
	map_begin.y += rooms[0].coords.y;
	map_end.x += rooms[0].coords.x;
	map_end.y += rooms[0].coords.y;

	for (int i = 0; i < rooms.size(); i++)
	{
		if (rooms[i].coords.x < map_begin.x) 
			map_begin.x = rooms[i].coords.x;
		else if (rooms[i].coords.x + room_gen.GetRoomEdgeSize() > map_end.x)
			map_end.x = rooms[i].coords.x + room_gen.GetRoomEdgeSize();

		if (rooms[i].coords.y < map_begin.y) 
			map_begin.y = rooms[i].coords.y;
		else if (rooms[i].coords.y + room_gen.GetRoomEdgeSize() > map_end.y)
			map_end.y = rooms[i].coords.y + room_gen.GetRoomEdgeSize();
	}


	width = map_end.x - map_begin.x;
	height = map_end.y - map_begin.y;

	map.resize(height);
	for (int y = 0; y < height; y++)
	{
		map[y].resize(width);
		for (int x = 0; x < width; x++)
			map[y][x] = Wall;
	}



	int offset_x = map_begin.x < 0 ? -map_begin.x : map_begin.x;
	int offset_y = map_begin.y < 0 ? -map_begin.y : map_begin.y;

	for (int i = 0; i < rooms.size(); i++)
	{
		rooms[i].coords.x += offset_x;
		rooms[i].coords.y += offset_y;
	}
	

	for (int i = 0; i < rooms.size(); i++)
	{
		DrawLevelStructureOnMap(map, rooms[i].content, rooms[i].coords);
	}

	for (int i = 0; i < tunnels.size(); i++)
	{
		tunnels[i].coords.x += offset_x;
		tunnels[i].coords.y += offset_y;
		DrawLevelStructureOnMap(map, tunnels[i].content, tunnels[i].coords);
	}

	//	DrawSpacialBlocksOnMap();
	target.Load(map);
}


void LevelGenerator::DrawSpacialBlocksOnMap()
{
	/*
	for (int y = 0; y < map.; y++)
		for (int x = 0; x < width_; x++)
			basic_map_[y][x] = Wall;

	int regions_num = rand() % width_ + height_ + 20;
	Block type;

	for (int i = 0; i < regions_num; i++)
	{
		type = rand() % (TotalBlockTypes - 4) + 4;

		switch (type)
		{
		case Stone:
			GenerateSpecialRegion({ rand() % width_, rand() % height_ },
				rand() % 2 + 1, rand() % 2 + 1, Stone);
			break;
		case StoneCracked:
			GenerateSpecialRegion({ rand() % width_, rand() % height_ },
				rand() % 2 + 1, rand() % 2 + 1, StoneCracked);
			break;
		case StoneMossy:
			GenerateSpecialRegion({ rand() % width_, rand() % height_ },
				rand() % 2 + 1, rand() % 2 + 1, StoneMossy);
			break;
		case Gravel:
			GenerateSpecialRegion({ rand() % width_, rand() % height_ },
				rand() % 2 + 1, rand() % 2 + 1, Gravel);
			break;
		}
	}*/
}

void LevelGenerator::GenerateSpecialRegion(
	Point const & a, 
	int max_radius_x, 
	int max_radius_y, 
	Block type)
{
/*
	Point start, end;
	int points_num;

	if (a.x - max_radius_x <= 0) start.x = 0;
	else start.x = a.x - max_radius_x;

	if (a.y - max_radius_y <= 0) start.y = 0;
	else start.y = a.y - max_radius_y;

	if (a.x + max_radius_x >= width_ - 1) end.x = width_ - 1;
	else end.x = a.x + max_radius_x;

	if (a.y + max_radius_y >= height_ - 1) end.y = height_ - 1;
	else end.y = a.y + max_radius_y;

	if (max_radius_x > 0 && max_radius_y > 0)
		points_num = rand() % ((end.x - start.x) * (end.y - start.y) + 3);
	else
		points_num = 1;

	for (int x, y, i = 0; i < points_num;)
	{
		x = rand() % (end.x - start.x + 1) + start.x;
		y = rand() % (end.y - start.y + 1) + start.y;

		basic_map_[y][x] = type;
		i++;
	}
	*/
}

void LevelGenerator::DrawLevelStructureOnMap(
	Map2D & map, 
	LevelStructure const & level_structure, 
	Point coords)
{
	int y = 0, x = 0;

	while (y < level_structure.GetHeight() && coords.y + y < map.size())
	{
		while (x < level_structure.GetWidth() && coords.x + x < map[y].size())
		{
			if (level_structure.GetBlock(x, y) != None)
			{
				map[coords.y + y][coords.x + x] = level_structure.GetBlock(x, y);
			}
			++x;
		}

		x = 0;
		++y;
	}
}

bool LevelGenerator::CheckRoomCoords(
	Point const & child_room_coords, 
	std::vector<Room> const & rooms, 
	int room_edge_size)
{
	Point child[4]
	{
		child_room_coords,
		{ 
			child_room_coords.x + room_edge_size - 1,
			child_room_coords.y 
		},
		{
			child_room_coords.x, 
			child_room_coords.y + room_edge_size - 1 
		},
		{ 
			child_room_coords.x + room_edge_size - 1, 
			child_room_coords.y + room_edge_size - 1 
		}
	};

	for (int i = 0; i < rooms.size(); i++)
	{
		int x1 = rooms[i].coords.x;
		int x2 = rooms[i].coords.x + room_edge_size - 1;
		int y1 = rooms[i].coords.y;
		int y2 = rooms[i].coords.y + room_edge_size - 1;

		for (int j = 0; j < 4; j++)
		{
			if (child[j].x >= x1 &&
				child[j].x <= x2 &&
				child[j].y >= y1 &&
				child[j].y <= y2) return false;
		}
	}

	return true;
}


/*
 * CODER-DOJO: zamiast spawdzac kazde mozliwe polozenie prostokata na strefie,
 * wystarczy sprawdzic dwa skrajne polozenia - dwa skrajne prostokaty
 * zajma 100% powierzchni strefy
 */
bool LevelGenerator::CheckFreeSpaceForRoomCoords(
	std::vector<Room> const & rooms, 
	Room const & master, 
	int room_edge_size)
{
	for (int i = 0; i < total_level_structure_sides; ++i)
	{
		Point temp;
		switch (i)
		{
		case top:
			temp = { master.coords.x, master.coords.y - room_edge_size };
			break;
		case left:
			temp = { 
				master.coords.x - room_edge_size, master.coords.y };
			break;
		case bottom:
			temp = { 
				master.coords.x, master.coords.y + room_edge_size };
			break;
		case right:
			temp = { 
				master.coords.x + room_edge_size, master.coords.y };
			break;
		case top_left:
			temp = { 
				master.coords.x + room_edge_size, master.coords.y - room_edge_size };
			break;
		case top_right:
			temp = { 
				master.coords.x - room_edge_size, master.coords.y - room_edge_size };
			break;
		case bottom_left:
			temp = { 
				master.coords.x - room_edge_size, master.coords.y + room_edge_size };
			break;
		case bottom_right:
			temp = { 
				master.coords.x + room_edge_size, master.coords.y + room_edge_size };
			break;
		}

		if (CheckRoomCoords(temp, rooms, room_edge_size))
			return true;
	}
	return false;
}


/*
 *	CODER-DOJO: Funkcja zwaraca falsz jezeli nie ma miejsca na nowy pokoj
 *	oraz prawde jezeli takowe jest. Pierwszy parametr to punkt, do ktorego
 *  zapisywane sa prawidlowe koordynaty
 */
void LevelGenerator::GenerateChildRoomCoords(
	Point & valid_room_coords, 
	std::vector<Room> const & rooms, 
	Room const & master, 
	int room_edge_size)
{
	//if (CheckFreeSpaceForRoomCoords(rooms, master, room_edge_size))
	//{
		Point temp;
		do
		{
			switch (rand() % 4)
			{
			case top_right:
				temp = {
					master.coords.x + rand() % (room_edge_size + 1),
					master.coords.y - room_edge_size
				};
				break;
			case top_left:
				temp = {
					master.coords.x - room_edge_size,
					master.coords.y - rand() % (room_edge_size + 1)
				};
				break;
			case bottom_left:
				temp = {
					master.coords.x - rand() % (room_edge_size + 1),
					master.coords.y + room_edge_size
				};
				break;
			case bottom_right:
				temp = {
					master.coords.x + room_edge_size,
					master.coords.y + rand() % (room_edge_size + 1)
				};
				break;
			}
		}
		while (!CheckRoomCoords(temp, rooms, room_edge_size));

		valid_room_coords = temp;
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}
}
