#include "MainMenuState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>
#include "GameState.hpp"

ArtaEngine::MainMenuState::MainMenuState(GameDataRef data) : _data(data)
{

}

void ArtaEngine::MainMenuState::Init()
{
	this->m_view = _data->window.getDefaultView();

	// load assets.
	this->_data->assets.LoadTexture("Background", Main_Menu_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("Generic Button", GENERIC_BUTTON);
	this->_data->assets.LoadTexture("GameTitle", MAIN_MENU_TITLE_PATH);
	this->_data->assets.LoadFont("OpenSansFont", FONT_OPEN_SANS);

	// reference loaded assets.
	this->_background.setTexture(this->_data->assets.GetTexture("Background"));
	this->_playButton.setTexture(this->_data->assets.GetTexture("Generic Button"));
	this->_title.setTexture(this->_data->assets.GetTexture("GameTitle"));
	this->_playTxt.setFont(this->_data->assets.GetFont("OpenSansFont"));

	// adjust the UI
	float playButtonX = (SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2);
	float playButtonY = (SCREEN_HEIGHT / 3 * 2) - (this->_playButton.getGlobalBounds().height / 2);

	this->_playButton.setPosition(playButtonX, playButtonY);

	this->_playTxt.setCharacterSize(12);
	this->_playTxt.setFillColor(sf::Color::Black);
	this->_playTxt.setString("PLAY");

	this->_playTxt.setPosition(
		this->_playButton.getPosition().x + (this->_playButton.getLocalBounds().width - this->_playTxt.getLocalBounds().width) / 2,
		this->_playButton.getPosition().y + (this->_playButton.getLocalBounds().height - this->_playTxt.getLocalBounds().height) / 2
	);

	this->_title.setPosition(
		(SCREEN_WIDTH / 2) - (static_cast<float>(this->_title.getGlobalBounds().width) / 2),
		this->_title.getGlobalBounds().height * 0.1f);

}

void ArtaEngine::MainMenuState::HandleInput()
{
	sf::Event sfEvent;

	while (this->_data->window.pollEvent(sfEvent))
	{
		if (sf::Event::Closed == sfEvent.type)
		{
			this->_data->window.close();
		}

		if (this->_data->input.isSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
		{
			std::cout << "Go to Game Screen" << std::endl;
			this->_data->machine.AddState(StateRef(new GameState(_data)), true);
		}
	}
}

void ArtaEngine::MainMenuState::Update(float dt)
{

}

void ArtaEngine::MainMenuState::Draw(float dt)
{
	this->_data->window.clear();

	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_playButton);
	this->_data->window.draw(this->_playTxt);
	this->_data->window.draw(this->_title);

	this->_data->window.display();
}
