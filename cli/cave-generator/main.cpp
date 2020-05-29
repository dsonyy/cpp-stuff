#include <iostream>
#include <cstdlib>
#include <string>

#include "room-gen.h"
#include "tunnel-gen.h"
#include "level-gen.h"

void WriteHelp() {
	std::cout << "Usage:\n"
		<< "\t-r / --room\t\tGenerate room instead of level\n"
		<< "\t-s / --seed\t\tSepcify random seed\n"
		<< "\t-h / --help\t\tDisplay this message\n";
}

int main(int argc, char ** argv)
{
	bool room_only = false;
	unsigned seed = 1;
	
	if (argc == 1) {
		WriteHelp();
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		if (std::strcmp(argv[i], "-r") == 0 || std::strcmp(argv[i], "--room") == 0) {
			room_only = true;
		}
		else if (std::strcmp(argv[i], "-l") == 0 || std::strcmp(argv[i], "--level") == 0) {

		}
		else if (std::strcmp(argv[i], "-s") == 0 || std::strcmp(argv[i], "--seed") == 0) {
			if (++i >= argc) {
				std::cerr << "Please specify valid seed.\n";
				return 1;
			}
			try {
				seed = std::stoi(argv[i]);
			}
			catch (...) {
				std::cerr << "Please specify valid seed.\n";
				return 1;
			}
		}
		else if (std::strcmp(argv[i], "-h") == 0 || std::strcmp(argv[i], "--help") == 0) {
			WriteHelp();
			return 0;
		}
		else {
			std::cerr << "Invalid arguments.\n";
			WriteHelp();
			return 1;
		}
	}

	srand(seed);
	TunnelGenerator tunnel_gen;
	RoomGenerator room_gen;
	LevelGenerator level_gen(room_gen, tunnel_gen);

	if (room_only) {
		Room room = room_gen.Generate();
		room.Write();
	}
	else {
		Level level = level_gen.Generate();
		level.Write();
	}

	return 0;
}