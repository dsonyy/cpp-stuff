#ifndef _H_TUNNEL
#define _H_TUNNEL


#include "map.h"


class Tunnel : public Map
{
public:
	void operator=(const Tunnel & other_tunnel);

	inline LocalPoint  GetLocalBeginPoint() const;
	inline LocalPoint  GetLocalEndPoint() const;
	inline GlobalPoint GetGlobalCoords() const;

private:
	LocalPoint begin_;
	LocalPoint end_;
	GlobalPoint coords_;

	friend class TunnelGenerator;
};


inline LocalPoint Tunnel::GetLocalBeginPoint() const
{
	return begin_;
}
	   
inline LocalPoint Tunnel::GetLocalEndPoint() const
{
	return end_;
}

inline GlobalPoint Tunnel::GetGlobalCoords() const
{
	return coords_;
}


#endif // !_H_TUNNEL
