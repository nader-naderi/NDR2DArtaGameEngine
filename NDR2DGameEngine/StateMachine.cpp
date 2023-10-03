#include "StateMachine.hpp"

namespace ArtaEngine
{
	void StateMachine::AddState(StateRef newState, bool isReplacing)
	{
		this->_isAdding = true;
		this->_isReplacing = isReplacing;
		this->_newState = std::move(newState);
	}

	void StateMachine::RemoveState()
	{
		// turn on the remove flag.
		this->_isRemoving = true;
	}

	void StateMachine::ProcessStateChanges()
	{
		// is should remove state and is states are not empty?
		if (this->_isRemoving && !this->_states.empty())
		{
			// remove the top state.
			this->_states.pop();
			
			// any state remained?
			if (!this->_states.empty())
			{
				// resume the current top state.
				this->_states.top()->Resume();
			}

			// turn remove flag to off.
			this->_isRemoving = false;
		}

		// are we going to add a state?
		if (this->_isAdding)
		{
			// is not empty?
			if (!this->_states.empty())
			{
				// is replacing?
				if (this->_isReplacing)
				{
					// remove the top state.
					this->_states.pop();
				}
				else // not replacing?
				{
					// just pause the state operations.
					this->_states.top()->Pause();
				}
			}
			
			// Add the new state to the stack.
			this->_states.push(std::move(this->_newState));

			// initialize the added state.
			this->_states.top()->Init();

			// turn the add flag to off.
			this->_isAdding = false;
		}
	}

	StateRef& StateMachine::GetActiveState()
	{
		return this->_states.top();
	}
}