#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

namespace ArtaEngine {

	class GameObject;

	class Component
	{
	public:
		virtual void Update() {}
		virtual void Render(sf::RenderTarget& window) {}
		virtual bool IsActive() const { return true; }
		virtual void SetOwner(GameObject* owner) { gameObject = owner; }

	protected:
		GameObject* gameObject = nullptr;
	};

	class Transform : public Component {
	public:
		Transform(float x = 0.0f, float y = 0.0f, float rotation = 0.0f, float scaleX = 1.0f, float scaleY = 1.0f)
			: position(x, y), rotation(rotation), scale(scaleX, scaleY) {}

		void Update() override {}

		// Getters and Setters for position, rotation, and scale
		sf::Vector2f GetPosition() const { return position; }
		void SetPosition(sf::Vector2f newPos) { position = newPos; }

		float GetRotation() const { return rotation; }
		void SetRotation(float newRotation) { rotation = newRotation; }

		sf::Vector2f GetScale() const { return scale; }
		void SetScale(sf::Vector2f newScale) { scale = newScale; }

		// Methods for translating and rotating
		void Translate(sf::Vector2f delta) { position += delta; }
		void Rotate(float deltaRotation) { rotation += deltaRotation; }

		// Methods to set the position, rotation, and scale directly
		void SetTransform(sf::Vector2f newPos, float newRotation, sf::Vector2f newScale) {
			position = newPos;
			rotation = newRotation;
			scale = newScale;
		}

	private:
		sf::Vector2f position;
		float rotation; // in degrees
		sf::Vector2f scale;
	};

	class SpriteRenderer : public Component, public sf::Drawable, public sf::Transformable
	{
	public:
		SpriteRenderer(sf::Texture* texture)
		{
			this->_sprite.setTexture(*texture);
		}

		void Render(sf::RenderTarget& target) override
		{
			target.draw(this->_sprite, this->getTransform());
		}

	private:
		sf::Sprite _sprite;
	public:
		sf::Sprite& GetSprite() {
			return _sprite;
		}
	};

	class ColliderComponent : public Component {
	public:
		ColliderComponent(sf::FloatRect rect)
			: collisionRect(rect), spriteRenderer(nullptr)
		{

		}

		// Override for custom collision handling
		void OnCollide(GameObject& other) {
			// Add your collision response logic here
		}

		ColliderComponent(SpriteRenderer* spriteRenderer)
			: spriteRenderer(spriteRenderer) {
			// Automatically calculate the collision rect based on the sprite's bounds
			if (spriteRenderer != nullptr) {
				collisionRect = spriteRenderer->GetSprite().getGlobalBounds();
			}
			else {
				// If no SpriteRenderer is provided, initialize with an empty rectangle.
				collisionRect = sf::FloatRect(0.0f, 0.0f, 0.0f, 0.0f);
			}
		}

		const sf::FloatRect& GetCollisionRect() const {
			return collisionRect;
		}

	private:
		sf::FloatRect collisionRect;
		SpriteRenderer* spriteRenderer;
	};
	
	class RigidbodyComponent : public Component {
	public:
		RigidbodyComponent(float mass)
			: mass(mass), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f) {}

		void Update() override {
			// Update position based on velocity and acceleration
			velocity += acceleration;
			gameObject->transform().Translate(velocity);
		}

		// Apply a force to the rigidbody
		void ApplyForce(sf::Vector2f force) {
			acceleration += force / mass;
		}

		// Getters and setters for velocity and acceleration
		const sf::Vector2f& GetVelocity() const {
			return velocity;
		}

		void SetVelocity(const sf::Vector2f& newVelocity) {
			velocity = newVelocity;
		}

		const sf::Vector2f& GetAcceleration() const {
			return acceleration;
		}

		void SetAcceleration(const sf::Vector2f& newAcceleration) {
			acceleration = newAcceleration;
		}

	private:
		float mass;
		sf::Vector2f velocity;
		sf::Vector2f acceleration;
	};
}