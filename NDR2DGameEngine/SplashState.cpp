#include <sstream>
#include "SplashState.hpp"
#include <iostream>
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

ArtaEngine::SplashState::SplashState(GameDataRef data) : _data(data)
{
	
}

void ArtaEngine::SplashState::Init()
{
	this->m_view = _data->window.getDefaultView();

	this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

	_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
	_background.setOrigin(_background.getTexture()->getSize().x / 2, _background.getTexture()->getSize().y / 2);
	_background.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void ArtaEngine::SplashState::HandleInput()
{
	sf::Event sfEvent;

	while (this->_data->window.pollEvent(sfEvent))
	{
		if (sf::Event::Closed == sfEvent.type)
		{
			this->_data->window.close();
		}
	}
}

void ArtaEngine::SplashState::Update(float dt)
{
	if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		// Switch to the Main Menu
		std::cout << "Go to Main Menu" << std::endl;
		this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
	}
}

void ArtaEngine::SplashState::Draw(float dt)
{
	this->_data->window.clear();
	this->_data->window.draw(this->_background);
	this->_data->window.display();
}
