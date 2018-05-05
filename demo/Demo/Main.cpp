#include "WinPalette.h"
#include "WinConsole.h"
#include "CharEx.h"
#include <iostream>
#include <array>

int main(int argc, char ** argv)
{
	display::winapi::WinConsole con(60, 60);
	con.SetCursorMode(display::winapi::WinConsole::HIDE);

	std::cout << "A quick brown fox jumps over the lazy dog\n";
	con.Write(3, 3, { '$', 1,15 });
	while (1);
	return 0;
}