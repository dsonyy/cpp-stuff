#pragma once
#include <vector>
#include "state-manager-interface.h"

class StateManager
	: public IStateManager
{
public:
	StateManager();
	~StateManager();

	virtual void PushState(IState * new_top_state);
	virtual void PopState();
	virtual void Clear();

	virtual IState * GetTopState();
	
private:
	std::vector<IState *> state_;
};