// main.cpp
// the entry point of the program

#include "functions.h"
#include "headers.h"
#include "tunnel-generator.h"
#include "room-generator.h"
#include "level-generator.h"
#include "level-structure.h"
#include "path.h"
#include "IO.h"
#include "file-export.h"

using namespace std;

int main(int argc, char ** argv)
{
	bool freeze = false;
	bool looped = false;
	bool echo = false;

	time_t seed = 1/*time(NULL)*/;
	srand(seed);
	INFO("Level generator launched\n");
	INFO("Seed set to %i\n", seed);

	RoomGenerator room_gen;
	Room test_room = room_gen.Generate();


	while (1);

	/*for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "-l"))
		{
			INFO("Starting generating level\n");
			do
			{
				INFO("\n");
				LevelGenerator gen;
				LevelStructure test;
				gen.Create(test);
				test.Write();
			} while (looped);
		}
		else if (!strcmp(argv[i], "-t"))
		{
			INFO("Starting generating tunnel\n");
			do
			{
				INFO("-----------------\n");
				TunnelGenerator gen;
				LevelStructure test;
				Point a = { 100, 10 };
				Point b = { 10, 100 };
				gen.Create(test, a, b);
				test.Write();
			} while (looped);
		}
		else if (!strcmp(argv[i], "-r"))
		{
			INFO("Starting generating room\n");
			int specimen = 1;
			do
			{
				RoomGenerator gen;
				LevelStructure test;
				gen.Create(test);
				if (echo)
				{
					INFO("Specimen number: %i\n", specimen);
					specimen++;
					test.Write();
				}
			} while (looped);

		}
		else if (!strcmp(argv[i], "-p"))
		{
			INFO("Starting generating path\n");
			do
			{
				Point a = { rand() % 10, rand() % 10 };
				Point b = { rand() % 10, rand() % 10 };
				Path test;
				test.Draw(a, b);
				if (echo) test.Write();
			} while (looped);
		}
		else if (!strcmp(argv[i], "-freeze"))
			freeze = true;
		else if (!strcmp(argv[i], "-loop"))
			looped = true;
		else if (!strcmp(argv[i], "-echo"))
			echo = true;
		else
		{
			ERROR("Invalid argument: %s\n", argv[i]);
		}
	}
*/
	if (argc <= 1)
		WARNING("Didn't pass any argument. Nothing was done\n");

	if (freeze) while (true);
	INFO("Exiting from level generator");
	return 0;
}

