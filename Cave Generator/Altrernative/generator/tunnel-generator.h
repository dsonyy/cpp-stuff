#ifndef _H_TUNNEL_GENERATOR
#define _H_TUNNEL_GENERATOR


#include "map.h"
#include "tunnel.h"
#include "path.h"


class TunnelGenerator
{
public:
	TunnelGenerator();
	const Tunnel & Generate(
		Point a, 
		Point b
	) const;

private:
	void RandomCommonPoints(
		std::vector<LocalPoint> & common_points, 
		const Path & master
	) const;

	void DrawCommonPointsPath(
		const Point & a, 
		const std::vector<Point> & common_points, 
		const Point & b,
		const Path & path
	) const;

	void BuildPathOnMap(
		Tunnel & tunnel, 
		Path const & path,
		unsigned tunnel_size_x, 
		unsigned tunnel_size_y, 
		BlockType type = PathFloor
	) const;

	void FillIslands(
		Tunnel & tunnel
	) const;


	unsigned common_points_level_;
	bool fill_islands_;
};



#endif // _H_TUNNEL_GENERATOR