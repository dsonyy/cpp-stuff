#pragma once

#include "Display.h"
#include "Control.h"
#include "Game.h"
#include "Board.h"
#include "Player.h"


class Engine
{
public:
	enum GameMode { MENU, GAME, SCREEN }; 

	Engine(Display * display/*, Control * control*/);
	~Engine();

	void Init();

private:
	void Loop();
	void Draw();
	void Logic();

	Display * display_;
	Control * control_;

	Player * current_player_;
	Board * current_board_;
	Game * current_game_;

	GameMode current_gamemode_;
	bool running_;
};