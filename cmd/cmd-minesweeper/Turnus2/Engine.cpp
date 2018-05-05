#include "Engine.h"

#include <windows.h>
#include <conio.h>

Engine::Engine(Display * display/*, Control * control*/)
{
	display_ = display;
	//control_ = control;
	running_ = true;
	current_gamemode_ = GAME;
}

Engine::~Engine()
{
	if (current_player_ != NULL) delete current_player_;

	if (current_board_ != NULL) delete current_board_;
	
	if (current_game_ != NULL) delete current_game_;
}

void Engine::Init()
{ 
	current_player_ = new Player();
	current_player_->SetName("Ziomal");
	
	current_board_ = new Board({ 10,10 }, 16);

	current_game_ = new Game(current_player_, current_board_);

	//control_->Init();

    Loop();
}

void Engine::Loop()
{
	//while (running_)
	//{
	//	//control_->EventLoop();


	//	switch (current_gamemode_)
	//	{
	//	case GAME:
	//			
	//		break;
	//	}

	//}


	while (1)
	{
		Draw();

		if (current_player_->isAlive())
		{
			switch (_getch())
			{
			case 'w':
			case 'W':
				current_game_->GoUp();
				break;
			case 'a':
			case 'A':
				current_game_->GoLeft();
				break;
			case 's':
			case 'S':
				current_game_->GoDown();
				break;
			case 'd':
			case 'D':
				current_game_->GoRight();
				break;
			case 'k':
			case 'K':
				current_game_->Click();
				break;
			case 'l':
			case 'L':
				current_game_->SpecialClick();
				break;
			case ';':
				current_game_->Flag();
				break;
			}
		}
		else
		{
			display_->KillScreen(current_player_, current_board_);
		}

		Logic();
	}
}

void Engine::Draw()
{
	display_->DrawBoard(current_player_, current_board_);
}

void Engine::Logic()
{

}