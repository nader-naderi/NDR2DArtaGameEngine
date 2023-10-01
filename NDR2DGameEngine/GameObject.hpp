#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
// TODO: Create Components and add them to the gameobejcts. (Transform, SpriteRenderer, Rigidbody, CustomScriptBehaviour, etc. )
namespace ArtaEngine
{
	class GameObject
	{
	public:
		GameObject(GameDataRef data);

		void SetPosition(float x, float y);
		void SetRotation(float angle);
		void Rotate(float angle);
		void Update(float deltaTime);
		void Draw();

	private:
		GameDataRef _data;
		sf::Sprite _sprite;
		sf::Vector2f _position;
		std::string _name;
		float _rotation;
	};
}