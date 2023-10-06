#pragma once
#include <SFML/Graphics.hpp>
// TODO: Create Components and add them to the gameobejcts. (Transform, SpriteRenderer, Rigidbody, CustomScriptBehaviour, etc. )
namespace ArtaEngine
{
	class GameObject : public sf::Transformable, public sf::Drawable
	{
	public:
		GameObject();
		GameObject(std::string name);
		GameObject(std::string name, sf::Vector2f position);
		GameObject(std::string name, sf::Vector2f position, float angle);
		GameObject(std::string name, sf::Vector2f position, sf::Texture texture);
		GameObject(std::string name, sf::Vector2f position, float angle, sf::Texture sprite);
		GameObject(sf::Texture sprite);
		~GameObject() {}

		void SetTexture(sf::Texture sprite);
		void SetPosition(float x, float y);
		void SetPosition(sf::Vector2f newPosition);
		void SetRotation(float angle);
		void Rotate(float angle);
		void Update(float deltaTime);
		void HandleInput(sf::Event sfEvent);
		std::string GetName() { return _name; }
		
		bool HasTexture() const
		{
			return _sprite.getTexture() != nullptr;
		}

	protected:
		// fields
		sf::Sprite _sprite;
		sf::Vector2f _position;
		std::string _name;
		float _rotation;

		// methods.
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}