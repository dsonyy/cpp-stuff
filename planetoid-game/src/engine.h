#pragma once
#include <vector>
#include "error.h"
#include "state-interface.h"
#include "graphic-manager-interface.h"
#include "input-manager-interface.h"
#include "state-manager-interface.h"


class Engine
{
public:
	Engine() {}
	~Engine() {}

	void Init(IGraphicManager * graphic_manager,
		IInputManager * input_manager,
		IStateManager * state_manager);
	void Loop();
	void Cleanup();

	void operator=(const Engine &) = delete;
	Engine(const Engine &) = delete;

	static const int TICKS_PER_SECOND = 25;
	static const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	static const int MAX_FRAMESKIP = 5;
	static const int WINDOW_WIDTH = 1280;
	static const int WINDOW_HEIGHT = 720;

private:
	const int Ticks_per_second_ = 25;
	const int Max_frameskip_ = 5;
	const int Skip_ticks_ = 1000 / Ticks_per_second_;

	bool running_;

	IGraphicManager * graphic_manager_;
	IInputManager * input_manager_;
	IStateManager * state_manager_;
};
