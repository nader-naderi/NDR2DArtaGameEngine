#pragma once
#include "GameObject.hpp"

namespace ArtaEngine 
{
	class Scene
	{
	public:
		Scene() {}
		~Scene() {}

		void Init();
		void Update(float dt);

		void AddGameObject(GameObject& gameObejct);
		void RemoveGameObject(GameObject& gameObejct);
		void ClearScene();
		void HandleInput(sf::Event& sfEvent);
		void Draw(sf::RenderWindow& window);
	private:
		std::vector<GameObject> _gameObjects;
	};
}
