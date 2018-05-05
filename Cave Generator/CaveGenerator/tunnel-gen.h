#ifndef _H_TUNNEL_GENERATOR
#define _H_TUNNEL_GENERATOR


#include "map.h"
#include "tunnel.h"
#include "path.h"


class TunnelGenerator
{
public:
	TunnelGenerator();

	Tunnel Generate(
		Point a, 
		Point b
	);

	Tunnel GenerateAndCut(
		Point a,
		Point b
	);

private:
	void RandomCommonPoints(
		std::vector<MapPoint> & common_points, 
		const Path & master
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


	int speciment_counter_;
	unsigned common_points_level_;
	bool fill_islands_;
};



#endif // _H_TUNNEL_GENERATOR