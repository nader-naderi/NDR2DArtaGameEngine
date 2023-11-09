#include "ArtaBehaviour.hpp"
#include "DEFINITIONS.hpp"

#ifndef PLAYER
#define PLAYER

using namespace ArtaEngine;

namespace Astroids
{
	class PlayerController : public ArtaBehaviour
	{
	public:
		Transform m_transform;
		SpriteRenderer m_spriteRenderer;

		PlayerController(GameObject* gameObject, sf::Texture* texure)
		{
			m_transform = gameObject->transform();
			gameObject->AddComponent(std::make_shared<SpriteRenderer>(texure));
			m_spriteRenderer = *gameObject->GetComponent<SpriteRenderer>();
			m_transform.Init(&m_spriteRenderer.GetSprite());
			m_transform.SetPosition(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 200));
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
			//std::cout << "Player is calling from Update" << std::endl;

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

			if(&m_transform == NULL)
				std::cout << "No transform" << std::endl;

			sf::Vector2f movementDirection = sf::Vector2f(horizontalInput * moveSpeed, verticalInput * moveSpeed);
			
			//m_spriteRenderer.setPosition(movementDirection);

			m_transform.Translate(movementDirection);
		
			std::cout << "Player Position: " << m_transform.GetPosition().x << ", " << m_transform.GetPosition().y << std::endl;

		}

		void Shoot()
		{
			// Spawn projectile.
		}
	};
}

#endif // PLAYER