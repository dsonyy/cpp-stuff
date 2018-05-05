
#include "headers.h"
#include "functions.h"
#include "path.h"
#include "room.h"
#include "room-generator.h"



RoomGenerator::RoomGenerator()
{
	// TODO: initialization all variables from file
	effective_room_edge_ = 16;
	min_offset_ = 3;

	max_rectangles_num_ = 8;
	min_rectangles_num_ = 4;
	max_rectangle_edge_	= 7;
	min_rectangle_edge_ = 4;
	jerk_probalility_ = 60; // !=0

	room_edge_  = 2 * min_offset_ + effective_room_edge_;
	max_offset_	= room_edge_ - max_rectangle_edge_ - min_offset_;

	// TODO: check variables
}


const Room & RoomGenerator::Generate() const
{
	int rectangles_num = rand() %
		(max_rectangles_num_ - min_rectangles_num_ + 1) + min_rectangles_num_;

	Room temp;
	temp.center_points_.resize(rectangles_num);

	temp.map_.resize(room_edge_);
	for (int y = 0; y < room_edge_; y++)
	{
		temp.map_[y].resize(room_edge_);
		for (int x = 0; x < room_edge_; x++)
			temp.map_[y][x] = None;
	}

	
	for (int i = 0; i < rectangles_num; i++)
		temp.center_points_[i] = GenerateRectangle(temp);
	
	JerkEdges(temp);
	RemoveLonePoints(temp);
	GeneratePaths(temp);

	return temp;
}


LocalPoint RoomGenerator::GenerateRectangle(
	Room & room,
	BlockType type) const
{
	unsigned rectangle_x = rand() %
		(max_rectangle_edge_ - min_rectangle_edge_ + 1) + min_rectangle_edge_;
	unsigned rectangle_y = rand() %
		(max_rectangle_edge_ - min_rectangle_edge_ + 1) + min_rectangle_edge_;
	unsigned offset_x = rand() % 
		(max_offset_ - min_offset_ + 1) + min_offset_;
	unsigned offset_y = rand() %
		(max_offset_ - min_offset_ + 1) + min_offset_;
	LocalPoint center_point = { 
		rectangle_x / 2 + offset_x, 
		rectangle_y / 2 + offset_y 
	};

	for (int y = offset_y; y < offset_y + rectangle_y; y++)
	{
		for (int x = offset_x; x < offset_x + rectangle_x; x++)
			room.map_[y][x] = type;
	}

	return center_point;
}


void RoomGenerator::GeneratePaths(
	Room & room) const
{
	for (int i = 0; i < room.center_points_.size(); i++)
	{
		for (int j = i + 1; j < room.center_points_.size(); j++)
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
			if (room.map_[y][x] == RoomFloor &&
			   (room.map_[y + 1][x] == None ||
				room.map_[y - 1][x] == None ||
				room.map_[y][x + 1] == None ||
				room.map_[y][x - 1] == None))
			{
				if (rand() % jerk_probalility_ == 0)
					room.map_[y][x] = None;
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
			if (room.map_[y][x] == RoomFloor &&
				room.map_[y + 1][x] == None &&
				room.map_[y - 1][x] == None &&
				room.map_[y][x + 1] == None &&
				room.map_[y][x - 1] == None)
			{
				room.map_[y][x] = None;
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
		room.map_[path.GetPoint(i).y][path.GetPoint(i).x] = type;
}
