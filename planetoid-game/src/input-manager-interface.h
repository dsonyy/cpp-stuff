#pragma once
#include "command.h"
#include "error.h"

class IInputManager
{
public:
	~IInputManager() {}

	virtual error Init() = 0;
	virtual void Cleanup() = 0;
	virtual void HandleInput() = 0;
};