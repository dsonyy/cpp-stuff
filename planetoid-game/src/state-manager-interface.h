#pragma once
#include "state-interface.h"

class IStateManager
{
public:
	~IStateManager() {}

	virtual void PushState(IState * new_top_state) = 0;
	virtual void PopState() = 0;
	virtual void Clear() = 0;

	virtual IState * GetTopState() = 0;
};