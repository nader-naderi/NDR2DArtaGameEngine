#include "SceneManager.hpp"

ArtaEngine::SceneManager::SceneManager() : _activeSceneIndex(-1)
{
	_scenes.push_back(Scene());
	_activeSceneIndex++;
}

void ArtaEngine::SceneManager::AddGameObject(GameObject& gameObejct)
{
	if (_activeSceneIndex >= 0 && _activeSceneIndex < _scenes.size())
	{
		_scenes[_activeSceneIndex].AddGameObject(gameObejct);
	}
}

void ArtaEngine::SceneManager::RemoveGameObject(GameObject& gameObejct)
{
	if (_activeSceneIndex >= 0 && _activeSceneIndex < _scenes.size())
	{
		_scenes[_activeSceneIndex].RemoveGameObject(gameObejct);
	}
}

void ArtaEngine::SceneManager::DrawActiveScene(sf::RenderWindow& window)
{
	if (_activeSceneIndex >= 0 && _activeSceneIndex < _scenes.size())
	{
		_scenes[_activeSceneIndex].Draw(window);
	}
}

void ArtaEngine::SceneManager::ClearScenes()
{
	_scenes.clear();
	_activeSceneIndex = -1;
}

ArtaEngine::Scene& ArtaEngine::SceneManager::GetActiveScene()
{
	if (_activeSceneIndex >= 0 && _activeSceneIndex < _scenes.size())
		return _scenes[_activeSceneIndex];

	static Scene invalidScene;
	return invalidScene;
}
