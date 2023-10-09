#include "ArtaBehaviour.hpp"
#include "DEFINITIONS.hpp"

#ifndef PLAYER
#define PLAYER

using namespace ArtaEngine;

namespace Astroids
{
	class Player : public ArtaBehaviour
	{
	public:
		Player(sf::Texture& texture, ArtaEngine::GameObject* gameObject)
		{
			GameObject* obj = gameObject;
			obj->AddComponent(std::make_shared<SpriteRenderer>(&texture));

			// Add Components and initialize them.
			obj->transform().Init(&obj->GetComponent<SpriteRenderer>()->GetSprite());

			obj->transform().SetPosition(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 200));
		}


		void Awake() override
		{
			std::cout << "Player is calling from awake" << std::endl;
		}

		void Start() override
		{
			// Initialize the player.
			std::cout << "Player is calling from Start" << std::endl;
		}

		void Update(float dt) override
		{
			std::cout << "Player is calling from Update" << std::endl;

			// player logic.
			Move();
			Shoot();
		}

	private:
		float moveSpeed = 10.0f;
		void Move()
		{
			float horizontalInput = InputManager::GetAxis("Horizontal");
			float verticalInput = InputManager::GetAxis("Vertical");

			Transform transform = GetGameObject()->transform();

			sf::Vector2f movementDirection = sf::Vector2f(horizontalInput * moveSpeed, verticalInput * moveSpeed);

			transform.Translate(movementDirection);
		}

		void Shoot()
		{
			// Spawn projectile.
		}
	};
}

#endif // PLAYER