#include "GameState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>
#include "PauseState.hpp"
#include "GameOverState.hpp"
#include "Component.hpp"
#include "Player.hpp"

// this is our editor state. we need runtime state as well.
ArtaEngine::GameState::GameState(GameDataRef data) : _data(data)
{

}

void ArtaEngine::GameState::Init()
{
	this->m_view = _data->window.getDefaultView();

	gameState = GAME_STATE_PLAYING;

	// asset loader
	// TODO: Show all of the assets inside of the assets explorer (project dispaly or something.)
	this->_data->assets.LoadTexture("HUD", HUD_FILEPATH);
	this->_data->assets.LoadTexture("Player", PLAYER_NORMAL_FILEPATH);
	
	// GameObject Creation processA:
	// TODO: could be the In Editor gameobject creation process.
	GameObject player = GameObject("Player");

	// attach the created custom script arta behaviour to the gameObject:
	// TODO: Add a new componenet in the inspector by add component button.
	// TODO: Show in the inspector all of the copmonents attached
	player.AddComponent(std::make_shared<Astroids::PlayerController>(&player, &this->_data->assets.GetTexture("Player")));
	
	// add the created gameobject to the scene.
	_data->sceneManager.AddGameObject(player);

	// rest. (all of them have to be in the ECS and editor pipeline)
	_background.setTexture(this->_data->assets.GetTexture("Background"));
	_pauseButton.setTexture(this->_data->assets.GetTexture("Generic Button"));
	_hud.setTexture(this->_data->assets.GetTexture("HUD"));
	_pauseTxt.setFont(this->_data->assets.GetFont("OpenSansFont"));

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
			//this->_data->machine.AddState(StateRef(new PauseState(_data)), false);
			this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
		}

		_data->sceneManager.GetActiveScene().HandleInput(sfEvent);
	}
}

void ArtaEngine::GameState::Update(float dt)
{
	_data->sceneManager.GetActiveScene().Update(dt);

	UpdateCameraBehaviour(dt);
}

void ArtaEngine::GameState::Draw(float dt)
{
	this->_data->window.clear();


	// draw toolbar
	this->_data->window.setView(m_toolbarView);

	this->_data->window.draw(this->_background);

	this->_data->window.setView(m_view);

	this->_data->window.draw(this->_pauseTxt);
	this->_data->window.draw(this->_pauseButton);
	this->_data->window.draw(this->_hud);
	this->_data->window.setView(m_camera);
	_data->sceneManager.DrawActiveScene(this->_data->window);

	this->_data->window.display();
}

void ArtaEngine::GameState::UpdateCameraBehaviour(float dt)
{
	sf::Vector2f horizontal = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f vertical = sf::Vector2f(0.0f, 0.0f);

	float moveSpeed = 20.0f * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		horizontal = sf::Vector2f(-moveSpeed, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		horizontal = sf::Vector2f(moveSpeed, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		vertical = sf::Vector2f(0.0f, moveSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		vertical = sf::Vector2f(0.0f, -moveSpeed);
	}

	m_camera.move(horizontal + vertical);
}
