#include <iostream>
#include <vector>
#include "tunnel-gen.h"
#include "tunnel.h"
#include "path.h"

TunnelGenerator::TunnelGenerator()
{
	common_points_level_ = 10; //!=0
	fill_islands_ = true;
}

Tunnel TunnelGenerator::Generate(
	Point a,
	Point b)
{
	int offset_x = 0, offset_y = 0;

	if (a.x < offset_x) offset_x = a.x;
	if (a.y < offset_y) offset_y = a.y;
	if (b.x < offset_x) offset_x = b.x;
	if (b.y < offset_y) offset_y = b.y;

	a = { a.x - offset_x, a.y - offset_y };
	b = { b.x - offset_x, b.y - offset_y };

	Tunnel temp;
	temp.begin_ = a;
	temp.end_ = b;
	Path master, side;
	std::vector<MapPoint> common_points;

	int tunnel_size_x = (a.x > b.x ? a.x : b.x) + 1;
	int tunnel_size_y = (a.y > b.y ? a.y : b.y) + 1;

	master.Draw(a, b);
	common_points.resize(master.GetLenght() / common_points_level_);

	temp.block_array_.resize(tunnel_size_y);
	for (int y = 0; y < tunnel_size_y; y++)
	{
		temp.block_array_[y].resize(tunnel_size_x);
		for (int x = 0; x < tunnel_size_x; x++)
			temp.block_array_[y][x] = None;
	}

	RandomCommonPoints(common_points, master);

	side.Draw(a, a);
	for (int i = 0; i < common_points.size(); i++)
		side.AddPoint(common_points[i]);
	side.AddPoint(b);

	BuildPathOnMap(temp, side, tunnel_size_x, tunnel_size_y);
	BuildPathOnMap(temp, master, tunnel_size_x, tunnel_size_y);
	if (fill_islands_)
	{
		FillIslands(temp);
	}

	temp.specimen_ = speciment_counter_++;


	return temp;
}


Tunnel TunnelGenerator::GenerateAndCut(
	Point a, 
	Point b)
{
	int offset_x = 0, offset_y = 0;

	//if (a.x < offset_x) offset_x = a.x;
	//if (a.y < offset_y) offset_y = a.y;
	//if (b.x < offset_x) offset_x = b.x;
	//if (b.y < offset_y) offset_y = b.y;

	offset_x = (a.x < b.x ? a.x : b.x);
	offset_y = (a.y < b.y ? a.y : b.y);
	a = { a.x - offset_x, a.y - offset_y };
	b = { b.x - offset_x, b.y - offset_y };
	
	Tunnel temp;
	temp.begin_ = a;
	temp.end_ = b;
	Path master, side;
	std::vector<MapPoint> common_points;

	unsigned tunnel_size_x = (a.x > b.x ? a.x : b.x) + 1;
	unsigned tunnel_size_y = (a.y > b.y ? a.y : b.y) + 1;

	master.Draw(a, b);
	common_points.resize(master.GetLenght() / common_points_level_);

	temp.block_array_.resize(tunnel_size_y);
	for (int y = 0; y < tunnel_size_y; y++)
	{
		temp.block_array_[y].resize(tunnel_size_x);
		for (int x = 0; x < tunnel_size_x; x++)
			temp.block_array_[y][x] = None;
	}

	RandomCommonPoints(common_points, master);

	side.Draw(a, a);
	for (int i = 0; i < common_points.size(); i++)
		side.AddPoint(common_points[i]);
	side.AddPoint(b);

	BuildPathOnMap(temp, side, tunnel_size_x, tunnel_size_y);
	BuildPathOnMap(temp, master, tunnel_size_x, tunnel_size_y);
	if (fill_islands_)
	{
		FillIslands(temp);
	}

	temp.specimen_ = speciment_counter_++;

	return temp;
}


void TunnelGenerator::RandomCommonPoints(
	std::vector<Point> & common_points, 
	Path const & master) const
{
	for (int i = 0; i < common_points.size(); i++)
		common_points[i] = master.GetPoint(common_points_level_ * i);
}


void TunnelGenerator::BuildPathOnMap(
	Tunnel & tunnel,
	Path const & path, 
	unsigned tunnel_size_x,
	unsigned tunnel_size_y,
	BlockType type) const
{
	for (int i = 0; i < path.GetLenght(); i++)
		tunnel.block_array_[path.GetPoint(i).y][path.GetPoint(i).x] = type;
}


void TunnelGenerator::FillIslands(
	Tunnel & tunnel) const
{
	for (int y = 0; y < tunnel.block_array_.size(); y++)
	{
		int first_point_place;
		int second_point_place;
		bool wait_for_second_point = false;
		bool fill = false;

		for (int x = 0; x < tunnel.block_array_[y].size(); x++)
		{
			if (tunnel.block_array_[y][x] == PathFloor)
			{
				if (!wait_for_second_point)
				{
					first_point_place = x;
					wait_for_second_point = true;
				}
				else
				{
					fill = true;
					second_point_place = x;
				}
			}
		}

		if (fill)
		{
			for (int x = first_point_place + 1; x < second_point_place; x++)
				tunnel.block_array_[y][x] = PathFloor;
		}
	}
}
