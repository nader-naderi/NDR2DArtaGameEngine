#include "GameObject.hpp"

ArtaEngine::GameObject::GameObject(GameDataRef data) : _data(data)
{

}

void ArtaEngine::GameObject::SetPosition(float x, float y)
{
	this->_position.x = x;
	this->_position.y = y;
	this->_sprite.setPosition(_position);
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

void ArtaEngine::GameObject::Draw()
{
	_data->window.draw(this->_sprite);
}
