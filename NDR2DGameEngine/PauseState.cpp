#include "PauseState.hpp"
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include <iostream>

ArtaEngine::PauseState::PauseState(GameDataRef data) : _data(data)
{

}

void ArtaEngine::PauseState::Init()
{
	this->m_view = _data->window.getDefaultView();

	this->_data->assets.LoadTexture("Pause Background", PAUSE_BG_FILEPATH);
	
	_background.setTexture(this->_data->assets.GetTexture("Pause Background"));
	_resumeBtn.setTexture(this->_data->assets.GetTexture("Generic Button"));
	_homeBtn.setTexture(this->_data->assets.GetTexture("Generic Button"));
	
	_resumeTxt.setFont(this->_data->assets.GetFont("OpenSansFont"));
	_homeTxt.setFont(this->_data->assets.GetFont("OpenSansFont"));

	this->_resumeBtn.setPosition((this->_data->window.getSize().x / 2) - (this->_resumeBtn.getLocalBounds().width / 2),
		(this->_data->window.getSize().y / 2 * 1.3f) - (this->_resumeBtn.getLocalBounds().height / 2));

	this->_homeBtn.setPosition((this->_data->window.getSize().x / 2) - (this->_homeBtn.getLocalBounds().width / 2),
		(this->_data->window.getSize().y / 2 * 1.4f) - (this->_homeBtn.getLocalBounds().height / 2));

	_background.setOrigin(_background.getGlobalBounds().width / 2, _background.getGlobalBounds().height / 2);
	_background.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	this->_homeTxt.setCharacterSize(12);
	this->_homeTxt.setFillColor(sf::Color::Black);
	this->_homeTxt.setString("Home");

	this->_homeTxt.setPosition(
		this->_homeBtn.getPosition().x + (this->_homeBtn.getLocalBounds().width - this->_homeTxt.getLocalBounds().width) / 2,
		this->_homeBtn.getPosition().y + (this->_resumeBtn.getLocalBounds().height - this->_homeTxt.getLocalBounds().height) / 2
	);

	this->_resumeTxt.setCharacterSize(12);
	this->_resumeTxt.setFillColor(sf::Color::Black);
	this->_resumeTxt.setString("Resume");

	this->_resumeTxt.setPosition(
		this->_resumeBtn.getPosition().x + (this->_resumeBtn.getLocalBounds().width - this->_resumeTxt.getLocalBounds().width) / 2,
		this->_resumeBtn.getPosition().y + (this->_resumeBtn.getLocalBounds().height - this->_resumeTxt.getLocalBounds().height) / 2
	);
}

void ArtaEngine::PauseState::HandleInput()
{
	sf::Event sfEvent;

	while (this->_data->window.pollEvent(sfEvent))
	{
		if (sf::Event::Closed == sfEvent.type)
		{
			this->_data->window.close();
		}

		if (this->_data->input.isSpriteClicked(this->_resumeBtn, sf::Mouse::Left, this->_data->window))
		{
			std::cout << "Resume the game" << std::endl;
			this->_data->machine.RemoveState();
		}

		if (this->_data->input.isSpriteClicked(this->_homeBtn, sf::Mouse::Left, this->_data->window))
		{
			std::cout << "Back to home" << std::endl;
			this->_data->machine.RemoveState();
			this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}
}

void ArtaEngine::PauseState::Update(float dt)
{

}

void ArtaEngine::PauseState::Draw(float dt)
{
	this->_data->window.clear();

	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_resumeBtn);
	this->_data->window.draw(this->_homeBtn);
	this->_data->window.draw(this->_resumeTxt);
	this->_data->window.draw(this->_homeTxt);

	this->_data->window.display();
}
