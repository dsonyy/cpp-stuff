#include <Windows.h>
#include <iostream> // temporary
#include "DisplayCmd.h"

DisplayCmd::DisplayCmd()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 100;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

}

void DisplayCmd::KillScreen(const Player * player, const Board * board)
{

}


void DisplayCmd::DrawBoard(const Player * player, const Board * board)
{
	system("cls");

	Coord i = { 0,0 };
	int test = board->GetSizeY();
	for (; i.y < board->GetSizeY(); ++i.y)
	{
		int test = board->GetSizeX();
		for (; i.x < board->GetSizeX(); ++i.x)
		{
			if (board->GetBlock(i).clicked == false && board->GetBlock(i).flag)
			{
				std::cout << "*";
			}
			else if (board->GetBlock(i).clicked == true)
			{
				if (board->GetBlock(i).number == Block::BOMB) std::cout << "X";
				else if (board->GetBlock(i).number == Block::EMPTY) std::cout << " ";
				else std::cout << board->GetBlock(i).number;
			}
			else
			{
				std::cout << char(219);
			}
		}
		std::cout << "\n";
		i.x = 0;
	}

	int x = SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(player->GetPosX()), SHORT(player->GetPosY()) });

}
