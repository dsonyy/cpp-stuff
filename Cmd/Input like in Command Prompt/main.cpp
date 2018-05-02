#include <string>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <vector>
#include "headers/Command.h"
#include "headers/GemBox.h"
#include "headers/Room.h"

int main()
{
	Command cmd;
	srand( time(NULL) );

	Room test(1);
	std::cout << test.m_boxes << std::endl;
	std::cout << test.m_npcs << std::endl;
	std::cout << test.m_mobs << std::endl;
	
	//while (cmd.get(0) != "exit");
	
	return 0;	
}