#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include <iostream>

ArtaEngine::GameOverState::GameOverState(GameDataRef data) : _data(data)
{

}

void ArtaEngine::GameOverState::Init()
{
	this->m_view = _data->window.getDefaultView();

	this->_data->assets.LoadTexture("GameOver Title", GAMEOVER_TITLE_FILEPATH);

	this->_gameOverTitle.setTexture(this->_data->assets.GetTexture("GameOver Title"));

	this->_retryBtn.setTexture(this->_data->assets.GetTexture("Generic Button"));
	this->_homeBtn.setTexture(this->_data->assets.GetTexture("Generic Button"));

	_retryTxt.setFont(this->_data->assets.GetFont("OpenSansFont"));
	_homeTxt.setFont(this->_data->assets.GetFont("OpenSansFont"));

	this->_retryBtn.setPosition((this->_data->window.getSize().x / 2) - (this->_retryBtn.getLocalBounds().width / 2),
		(this->_data->window.getSize().y / 2 * 1.3f) - (this->_retryBtn.getLocalBounds().height / 2));

	this->_homeBtn.setPosition((this->_data->window.getSize().x / 2) - (this->_homeBtn.getLocalBounds().width / 2),
		(this->_data->window.getSize().y / 2 * 1.4f) - (this->_homeBtn.getLocalBounds().height / 2));

	_gameOverTitle.setOrigin(_gameOverTitle.getGlobalBounds().width / 2, _gameOverTitle.getGlobalBounds().height / 2);
	_gameOverTitle.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	this->_homeTxt.setCharacterSize(12);
	this->_homeTxt.setFillColor(sf::Color::Black);
	this->_homeTxt.setString("Home");

	this->_homeTxt.setPosition(
		this->_homeBtn.getPosition().x + (this->_homeBtn.getLocalBounds().width - this->_homeTxt.getLocalBounds().width) / 2,
		this->_homeBtn.getPosition().y + (this->_retryBtn.getLocalBounds().height - this->_homeTxt.getLocalBounds().height) / 2
	);

	this->_retryTxt.setCharacterSize(12);
	this->_retryTxt.setFillColor(sf::Color::Black);
	this->_retryTxt.setString("Retry");

	this->_retryTxt.setPosition(
		this->_retryBtn.getPosition().x + (this->_retryBtn.getLocalBounds().width - this->_retryTxt.getLocalBounds().width) / 2,
		this->_retryBtn.getPosition().y + (this->_retryBtn.getLocalBounds().height - this->_retryTxt.getLocalBounds().height) / 2
	);
}

void ArtaEngine::GameOverState::HandleInput()
{
	sf::Event sfEvent;

	while (this->_data->window.pollEvent(sfEvent))
	{
		if (sf::Event::Closed == sfEvent.type)
		{
			this->_data->window.close();
		}

		if (this->_data->input.isSpriteClicked(this->_retryBtn, sf::Mouse::Left, this->_data->window))
		{
			std::cout << "retry game" << std::endl;
			this->_data->machine.AddState(StateRef(new GameState(_data)), true);
		}

		if (this->_data->input.isSpriteClicked(this->_homeBtn, sf::Mouse::Left, this->_data->window))
		{
			std::cout << "Back to home" << std::endl;
			this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}
}

void ArtaEngine::GameOverState::Update(float dt)
{

}

void ArtaEngine::GameOverState::Draw(float dt)
{
	this->_data->window.clear(sf::Color::Red);

	this->_data->window.draw(this->_gameOverTitle);
	this->_data->window.draw(this->_retryBtn);
	this->_data->window.draw(this->_homeBtn);
	this->_data->window.draw(this->_retryTxt);
	this->_data->window.draw(this->_homeTxt);

	this->_data->window.display();
}
