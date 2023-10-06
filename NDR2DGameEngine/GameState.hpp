#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace ArtaEngine
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

		void UpdateCameraBehaviour(float dt);

	private:
		GameDataRef _data;
		sf::Sprite _background;
		sf::Sprite _pauseButton;
		sf::Sprite _hud;
		sf::Text _pauseTxt;
		sf::View m_camera;
		sf::View m_toolbarView;
		int gameState;
	};
}