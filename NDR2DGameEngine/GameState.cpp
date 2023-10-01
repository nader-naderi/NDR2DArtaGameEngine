#include "GameState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>

ArtaEngine::GameState::GameState(GameDataRef data) : _data(data)
{

}

void ArtaEngine::GameState::Init()
{
	gameState = GAME_STATE_PLAYING;

	this->_data->assets.LoadTexture("Pause Button", GENERIC_BUTTON);
	this->_data->assets.LoadTexture("HUD", HUD_FILEPATH);
	this->_data->assets.LoadTexture("Player", PLAYER_NORMAL_FILEPATH);
	
	_background.setTexture(this->_data->assets.GetTexture("Background"));
	_pauseButton.setTexture(this->_data->assets.GetTexture("Pause Button"));
	_hud.setTexture(this->_data->assets.GetTexture("HUD"));
	_player.setTexture(this->_data->assets.GetTexture("Player"));

	_pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getLocalBounds().width,
		0);
	
	_pauseTxt.setFont(this->_data->assets.GetFont("OpenSansFont"));

	_hud.setPosition(this->_data->window.getSize().x - _hud.getLocalBounds().width, this->_data->window.getSize().y - _hud.getLocalBounds().height);
	
	this->_pauseTxt.setCharacterSize(12);
	this->_pauseTxt.setFillColor(sf::Color::Black);
	this->_pauseTxt.setString("PAUSE");

	this->_pauseTxt.setPosition(
		this->_pauseButton.getPosition().x + (this->_pauseButton.getLocalBounds().width - this->_pauseTxt.getLocalBounds().width) / 2,
		this->_pauseButton.getPosition().y + (this->_pauseButton.getLocalBounds().height - this->_pauseTxt.getLocalBounds().height) / 2
	);

	this->_player.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 200);

}

void ArtaEngine::GameState::HandleInput()
{
	sf::Event sfEvent;

	while (this->_data->window.pollEvent(sfEvent))
	{
		if (sf::Event::Closed == sfEvent.type)
		{
			this->_data->window.close();
		}

		if (this->_data->input.isSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->window))
		{
			std::cout << "Pause the Game" << std::endl;
		}
	}
}

void ArtaEngine::GameState::Update(float dt)
{

}

void ArtaEngine::GameState::Draw(float dt)
{
	this->_data->window.clear();

	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_pauseButton);
	this->_data->window.draw(this->_player);
	this->_data->window.draw(this->_hud);

	this->_data->window.display();
}
