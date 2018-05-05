#include <windows.h>
#include <algorithm>
#include <SDL.h>
#include <allegro5\allegro.h>

#include "error.h"
#include "engine.h"
#include "intro.h"


void Engine::Init(IGraphicManager * graphic_manager,
	IInputManager * input_manager,
	IStateManager * state_manager)
{	
	running_ = true;

	graphic_manager_ = graphic_manager;
	input_manager_ = input_manager;
	state_manager_ = state_manager;
	
	graphic_manager_->Init(1280,720);
	input_manager_->Init();

	Intro * intro = new Intro;
	state_manager_->PushState(intro);
	
}

void Engine::Cleanup()
{
	graphic_manager_->Cleanup();
	input_manager_->Cleanup();
	
}


void Engine::Loop()
{
	DWORD next_tick = GetTickCount();
	int loops;
	float interpolation;
	bool redraw = true;

	while (running_)
	{
		loops = 0;
		while (GetTickCount() > next_tick && loops < Max_frameskip_)
		{

			
			//input_manager_->HandleInput();
			state_manager_->GetTopState()->Update();

			next_tick += Skip_ticks_;
			loops++;

			printf("-");
		}

		interpolation = float(GetTickCount() + Skip_ticks_ - next_tick)
			/ float(Skip_ticks_);

		state_manager_->GetTopState()->Render(graphic_manager_, interpolation);
	}
}

