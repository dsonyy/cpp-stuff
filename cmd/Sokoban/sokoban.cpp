#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include "sokoban.h"

int main()
{
	Console cmd;
	std::cout << "WELCOME TO CMD-SOKOBAN!\n\n";
	cmd.help();
	std::cout << "\nPress '/' to use this commands while a game.\n\n";

	while (true)
		cmd.get();

	return 0;
}

