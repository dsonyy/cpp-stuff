#pragma once

#include "Board.h"
#include "Player.h"

class Display
{
public:
	virtual void DrawBoard(const Player * player, const Board * board) = 0;
	virtual void KillScreen(const Player * player, const Board * board) = 0;

};

