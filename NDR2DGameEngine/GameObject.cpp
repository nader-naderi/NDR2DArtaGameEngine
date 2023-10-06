#include "GameObject.hpp"

ArtaEngine::GameObject::GameObject()
{
	this->_name = "New GameObject";
}

ArtaEngine::GameObject::GameObject(std::string name)
{
	this->_name = name;
}

ArtaEngine::GameObject::GameObject(std::string name, sf::Vector2f position)
{
	this->_name = name;
	this->SetPosition(position);
}

ArtaEngine::GameObject::GameObject(std::string name, sf::Vector2f position, float angle)
{
	this->_name = name;
	this->SetPosition(position);
	this->SetRotation(angle);
}

ArtaEngine::GameObject::GameObject(std::string name, sf::Vector2f position, float angle, sf::Texture texture)
{
	this->_name = name;
	this->SetPosition(position);
	this->SetRotation(angle);
	SetTexture(texture);
}

ArtaEngine::GameObject::GameObject(std::string name, sf::Vector2f position, sf::Texture texture)
{
	this->_name = name;
	this->SetPosition(position);
	SetTexture(texture);
}

ArtaEngine::GameObject::GameObject(sf::Texture texture)
{
	SetTexture(texture);
}

void ArtaEngine::GameObject::SetTexture(sf::Texture texture)
{
	this->_sprite.setTexture(texture);
}

void ArtaEngine::GameObject::SetPosition(float x, float y)
{
	this->_position.x = x;
	this->_position.y = y;
	this->_sprite.setPosition(_position);
}

void ArtaEngine::GameObject::SetPosition(sf::Vector2f newPosition)
{
	SetPosition(newPosition.x, newPosition.y);
}

void ArtaEngine::GameObject::SetRotation(float angle)
{
	this->_rotation = angle;
	this->_sprite.setRotation(this->_rotation);
}

void ArtaEngine::GameObject::Rotate(float angle)
{
	this->_rotation += angle;
	this->_sprite.rotate(angle);
}

void ArtaEngine::GameObject::Update(float deltaTime)
{

}

void ArtaEngine::GameObject::HandleInput(sf::Event sfEvent)
{
	
	switch (sfEvent.type)
	{
	case sf::Event::KeyPressed:
		// Handle key presses
		if (sfEvent.key.code == sf::Keyboard::Left)
		{
			// Respond to the left arrow key press
			// You can add your custom logic here
		}
		// Add more cases for other key presses as needed
		break;

	case sf::Event::MouseButtonPressed:
		// Handle mouse button presses
		if (sfEvent.mouseButton.button == sf::Mouse::Left)
		{
			// Respond to the left mouse button click
			// You can add your custom logic here
		}
		// Add more cases for other mouse button presses as needed
		break;

		// Handle other types of events here as needed

	default:
		break;
	}
}

void ArtaEngine::GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_sprite, states);
}
