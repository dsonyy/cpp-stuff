#pragma once

#include "Coord.h"

class Control
{
public:
	virtual void Init() = 0;
	virtual void EventLoop() = 0;
	virtual bool IsRunning() = 0;

	virtual void GetEvent() = 0;
	virtual  bool CheckCloseButton() = 0;
	virtual Coord GetCursorPos() = 0;
};