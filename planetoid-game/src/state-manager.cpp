#include "state-interface.h"
#include "state-manager.h"

StateManager::StateManager()
{

}

StateManager::~StateManager() 
{

}

void StateManager::PushState(IState * new_top_state)
{
	new_top_state->Init();
	state_.push_back(new_top_state);
	
}

void StateManager::PopState()
{
	state_[state_.size() - 1]->Cleanup();

	state_.pop_back();
}

IState * StateManager::GetTopState()
{
	if (state_.size() == 0)
	{
		return nullptr;
	}
	
	return state_[state_.size() - 1];
	
}

void StateManager::Clear()
{
	state_.clear();
}