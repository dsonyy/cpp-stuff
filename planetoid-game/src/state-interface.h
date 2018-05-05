#pragma once
#include "graphic-manager-interface.h"

class IState
{
public:
	~IState() {}

	virtual void Init() = 0;
	virtual void Cleanup() = 0;
	
	virtual void Pause() = 0;
	virtual void Resume() = 0;
	
	virtual void Update() = 0;
	virtual void Render(IGraphicManager * graphic_manager, float interpolation) = 0;

	virtual bool IsInitialized() = 0;
	virtual bool IsPaused() = 0;

};
