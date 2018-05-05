#pragma once

#include "Display.h"
#include "Player.h"
#include "Board.h"

class DisplayCmd
	: public Display
{
public:
	DisplayCmd();

	// derived from Display interface
	virtual void DrawBoard(const Player * player, const Board * board);
	virtual void KillScreen(const Player * player, const Board * board);
private:


};
