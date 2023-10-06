#pragma once
#include "Scene.hpp"

namespace ArtaEngine
{
	class SceneManager
	{
	public:
		SceneManager();

		// ToDo use object pooling for add & removing objects.
		void AddGameObject(GameObject& gameObejct);
		void RemoveGameObject(GameObject& gameObejct);
		void DrawActiveScene(sf::RenderWindow& window);
		void ClearScenes();

		Scene& GetActiveScene();
	private:
		std::vector<Scene> _scenes;

		int _activeSceneIndex;
	};
}
