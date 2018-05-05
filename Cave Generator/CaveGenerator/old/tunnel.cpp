
#include "tunnel.h"

void Tunnel::operator=(const Tunnel & other_tunnel)
{
	map_ = other_tunnel.map_;
	id_ = other_tunnel.id_;

	begin_ = other_tunnel.begin_;
	end_ = other_tunnel.end_;
	coords_ = other_tunnel.coords_;
}