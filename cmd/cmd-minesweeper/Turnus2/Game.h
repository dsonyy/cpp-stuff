#pragma once

#include "Player.h"
#include "Board.h"
#include "Display.h"

class Game
{
public:
	Game(Player * player = NULL, Board * board = NULL);

	void GoUp();
	void GoDown();
	void GoLeft();
	void GoRight();

	bool Click();
	bool SpecialClick();
	void Flag();

	void SetPlayer(Player * player);
	void SetBoard(Board * board);

	Player * GetPlayer() const { return player_; }
	Board * GetBoard() const { return board_; }

private:
	Player * player_;
	Board * board_;
};
