
#include "tunnel.h"

void Tunnel::operator=(const Tunnel & other_tunnel)
{
	block_array_ = other_tunnel.block_array_;
	specimen_ = other_tunnel.specimen_;

	begin_ = other_tunnel.begin_;
	end_ = other_tunnel.end_;
	coords_ = other_tunnel.coords_;
}