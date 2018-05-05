#ifndef _H_LEVEL
#define _H_LEVEL

#include <vector>
#include "room-gen.h"
#include "tunnel-gen.h"
#include "map.h"




class Level : public Map
{
public:
	void operator=(const Level & other_level);

	inline LevelCoords GetRoomCoords(size_t index) const;
	inline LevelCoords GetTunnelCoords(size_t index) const;

private:
	std::vector<LevelCoords> rooms_area_;
	std::vector<LevelCoords> tunnels_area_;

	friend class LevelGenerator;
};




inline LevelCoords Level::
	GetRoomCoords(size_t room_index) const
{
	if (room_index < 0 && room_index >= rooms_area_.size())
	{
		// TODO: throw an exception
	}

	return rooms_area_[room_index];
}

inline LevelCoords Level::
	GetTunnelCoords(size_t tunnel_index) const
{
	if (tunnel_index < 0 && tunnel_index >= rooms_area_.size())
	{
		// TODO: throw an exception
	}

	return tunnels_area_[tunnel_index];
}


#endif // !_H_LEVEL
