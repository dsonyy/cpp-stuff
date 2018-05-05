#include "path.h"
#include "room.h"
#include "room-gen.h"

RoomGenerator::RoomGenerator()
{
	info << "Initializing room generator components\n";

	effective_room_edge_ = 16; //16
	min_offset_ = 3;

	max_rectangles_num_ = 8;
	min_rectangles_num_ = 4;
	max_rectangle_edge_ = 7;
	min_rectangle_edge_ = 4;
	jerk_probalility_ = 60; // !=0

	room_edge_ = 2 * min_offset_ + effective_room_edge_;
	max_offset_ = room_edge_ - max_rectangle_edge_ - min_offset_;

	room_counter_ = 0;
}


Room RoomGenerator::Generate()
{
	int rectangles_num = rand() %
		(max_rectangles_num_ - min_rectangles_num_ + 1) + min_rectangles_num_;

	Room temp;
	temp.center_points_.resize(rectangles_num);
	temp.coords_.corner[top_left]		= { 0,0 };
	temp.coords_.corner[top_right]		= { room_edge_ - 1, 0 };
	temp.coords_.corner[bottom_left]	= { 0,room_edge_ - 1};
	temp.coords_.corner[bottom_right]	= { room_edge_ - 1, room_edge_ - 1};


	temp.block_array_.resize(room_edge_);
	for (int y = 0; y < room_edge_; y++)
	{
		temp.block_array_[y].resize(room_edge_);
		for (int x = 0; x < room_edge_; x++)
			temp.block_array_[y][x] = None;
	}


	for (int i = 0; i < rectangles_num; i++)
		temp.center_points_[i] = GenerateRectangle(temp);

	JerkEdges(temp);
	RemoveLonePoints(temp);
	GeneratePaths(temp);

	temp.specimen_ = room_counter_++;
	temp.master_index_ = Room::unspecifed;

	return temp;
}


MapPoint RoomGenerator::GenerateRectangle(
	Room & room,
	BlockType type) const
{
	int rectangle_x = rand() %
		(max_rectangle_edge_ - min_rectangle_edge_ + 1) + min_rectangle_edge_;
	int rectangle_y = rand() %
		(max_rectangle_edge_ - min_rectangle_edge_ + 1) + min_rectangle_edge_;
	int offset_x = rand() %
		(max_offset_ - min_offset_ + 1) + min_offset_;
	int offset_y = rand() %
		(max_offset_ - min_offset_ + 1) + min_offset_;

	MapPoint center_point = {
		rectangle_x / 2 + offset_x,
		rectangle_y / 2 + offset_y
	};

	for (int y = offset_y; y < offset_y + rectangle_y; y++)
	{
		for (int x = offset_x; x < offset_x + rectangle_x; x++)
			room.block_array_[y][x] = type;
	}

	return center_point;
}


void RoomGenerator::GeneratePaths(
	Room & room) const
{
	for (size_t i = 0; i < room.center_points_.size(); i++)
	{
		for (size_t j = i + 1; j < room.center_points_.size(); j++)
		{
			Path connection;

			connection.Draw(
				room.center_points_[i],
				room.center_points_[j]
			);

			BuildPathOnMap(room, connection);
		}
	}
}


void RoomGenerator::JerkEdges(
	Room & room) const
{
	for (int y = min_offset_; y < max_offset_ + max_rectangle_edge_; y++)
	{
		for (int x = min_offset_; x < max_offset_ + max_rectangle_edge_; x++)
		{
			if (room.block_array_[y][x] == RoomFloor &&
				(room.block_array_[y + 1][x] == None ||
					room.block_array_[y - 1][x] == None ||
					room.block_array_[y][x + 1] == None ||
					room.block_array_[y][x - 1] == None))
			{
				if (rand() % jerk_probalility_ == 0)
					room.block_array_[y][x] = None;
			}
		}
	}
}


void RoomGenerator::RemoveLonePoints(
	Room & room) const
{
	for (int y = min_offset_; y < max_offset_ + max_rectangle_edge_; y++)
	{
		for (int x = min_offset_; x < max_offset_ + max_rectangle_edge_; x++)
		{
			if (room.block_array_[y][x] == RoomFloor &&
				room.block_array_[y + 1][x] == None &&
				room.block_array_[y - 1][x] == None &&
				room.block_array_[y][x + 1] == None &&
				room.block_array_[y][x - 1] == None)
			{
				room.block_array_[y][x] = None;
			}
		}
	}
}


void RoomGenerator::BuildPathOnMap(
	Room & room,
	Path const & path,
	BlockType type) const
{
	for (int i = 0; i < path.GetLenght(); i++)
		room.block_array_[path.GetPoint(i).y][path.GetPoint(i).x] = type;
}