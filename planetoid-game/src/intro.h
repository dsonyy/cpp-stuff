#pragma once
#include "graphic-manager-interface.h"
#include "state-interface.h"
#include "engine.h"

class Intro 
	: public IState
{
public:
	Intro() {}
	~Intro();

	virtual void Init();
	virtual void Cleanup();

	virtual void Pause();
	virtual void Resume();

	virtual void Update();
	virtual void Render(IGraphicManager * graphic_manager, float interpolation);

	virtual bool IsInitialized();
	virtual bool IsPaused();

	void operator=(const Intro &) = delete;
	Intro(const Intro &) = delete;

private:
	bool initialized_;
	bool paused_;
	
	struct force
	{
		float x;
		float y;
	};

	struct physic_rectangle
	{
		float x;
		float y;
		float width;
		float height;
		force forces;
	} rectangle_, ground_; 
	
	bool go_down;

};