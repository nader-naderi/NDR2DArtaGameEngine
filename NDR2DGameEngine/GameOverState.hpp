#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace ArtaEngine
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Sprite _retryBtn;
		sf::Sprite _homeBtn;
		sf::Sprite _gameOverTitle;

		sf::Text _retryTxt;
		sf::Text _homeTxt;
	};
}