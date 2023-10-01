#pragma once
#include <stack>
#include <memory>

#include "State.hpp"


namespace ArtaEngine
{
	/// <summary>
	/// Unique pointer to the state.
	/// </summary>
	typedef std::unique_ptr<State> StateRef;

	class StateMachine
	{
	public: 
		StateMachine() {}
		~StateMachine() {}

		/// <summary>
		/// Add a new state to the stack.
		/// </summary>
		/// <param name="newState">target state</param>
		/// <param name="isReplacing">are your replacing current statet?</param>
		void AddState(StateRef newState, bool isReplacing = true);
		void RemoveState();

		/// <summary>
		/// Runs on a start of a each iteration in the game.
		/// </summary>
		void ProcessStateChanges();

		StateRef& GetActiveState();

	private:
		std::stack<StateRef> _states;
		StateRef _newState;

		bool _isRemoving;
		bool _isAdding;
		bool _isReplacing;
	};
}

