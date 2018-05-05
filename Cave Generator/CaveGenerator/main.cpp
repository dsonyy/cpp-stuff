#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>

#include "console.h"
#include "room-gen.h"
#include "tunnel-gen.h"
#include "level-gen.h"


int main(int argc, char ** argv)
{
	int seed = 1;
	info << "Welcome to Cave Generator\n";
	info << "This session seed is " << seed << "\n";
	srand(seed);
	TunnelGenerator tunnel_gen;
	RoomGenerator room_gen;
	LevelGenerator level_gen(room_gen, tunnel_gen);

	while (1)
	{
		Level room = level_gen.Generate();
		room.Write();
		getchar();
	}



	return 0;
}