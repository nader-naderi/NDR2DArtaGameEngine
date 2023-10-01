#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace ArtaEngine
{
	class PauseState : public State
	{
	public:
		PauseState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Sprite _background;
		
		sf::Sprite _resumeBtn;
		sf::Text _resumeTxt;

		sf::Sprite _homeBtn;
		sf::Text _homeTxt;
	};
}