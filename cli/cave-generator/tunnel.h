#ifndef _H_TUNNEL
#define _H_TUNNEL


#include "map.h"


class Tunnel : public Map
{
public:
	void operator=(const Tunnel & other_tunnel);

	inline MapPoint		GetBeginPoint() const;
	inline MapPoint		GetEndPoint() const;

	inline const LevelCoords & GetCoords() const;
	inline void			SetCoords(const LevelCoords & other_coords);

private:
	MapPoint begin_;
	MapPoint end_;
	LevelCoords coords_;

	friend class TunnelGenerator;
};


inline MapPoint Tunnel::GetBeginPoint() const
{
	return begin_;
}
	   
inline MapPoint Tunnel::GetEndPoint() const
{
	return end_;
}

inline const LevelCoords & Tunnel::GetCoords() const
{
	return coords_;
}

inline void Tunnel::SetCoords(const LevelCoords & other_coords)
{
	coords_ = other_coords;
}

#endif // !_H_TUNNEL
