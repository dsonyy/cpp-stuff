#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include "sokoban.h"

void Console::get()
{
	std::cout << "/";
	std::cin.getline(cmd, MAX_CMD_NAME);

	while (!std::cin)
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "An error occured while entering data.\n/";
		std::cin.getline(cmd, MAX_CMD_NAME);
	}

	_strlwr(cmd);
	execute();
}

void Console::execute()
{
	if (strncmp(cmd, "exit", 4) == 0) exit(NULL);
	else if (strncmp(cmd, "help", 4) == 0) help();
	else if (strncmp(cmd, "load", sizeof "load"-1) == 0 && strlen(cmd) >= 6)
	{
		char mapName[MAX_MAP_NAME + 1];

		for (int i = 5, j = 0; i < MAX_MAP_NAME + 1; ++i, ++j)
			mapName[j] = cmd[i];

		Floor map(mapName);
		map.play();
	}
	else if (strncmp(cmd, "new", sizeof "new" - 1) == 0 && strlen(cmd) >= 5)
	{
		char mapName[MAX_MAP_NAME + 1];

		for (int i = 4, j = 0; i < MAX_MAP_NAME + 1; ++i, ++j)
			mapName[j] = cmd[i];

		Floor map(mapName);
		map.create();
	}
	else std::cout << "Unknown command.\n";

}

void Console::help()
{
	std::cout << "MENU                     Open menu\n";
	std::cout << "LOAD <map name>          Load choosen map file\n";
	std::cout << "NEW <map name>           Create new map file\n";
	std::cout << "HELP                     Show command list\n";
	std::cout << "EXIT                     Exit the game\n";
}