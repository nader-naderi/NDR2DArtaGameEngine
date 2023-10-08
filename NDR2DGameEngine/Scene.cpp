#include "Scene.hpp"
#include <iostream>

void ArtaEngine::Scene::Init()
{
}
void ArtaEngine::Scene::Update(float dt)
{
}
void ArtaEngine::Scene::AddGameObject(GameObject& gameObject)
{
	std::cout << "Insertion ";
	std::cout << gameObject.GetName() << std::endl;
	_gameObjects.push_back(gameObject);

}

void ArtaEngine::Scene::RemoveGameObject(GameObject& gameObject)
{
	_gameObjects.erase(std::remove_if(_gameObjects.begin(), _gameObjects.end(),
		[&gameObject](const GameObject& obj) { return &obj == &gameObject; }), _gameObjects.end());
}

void ArtaEngine::Scene::ClearScene()
{
	_gameObjects.clear();
}

void ArtaEngine::Scene::HandleInput(sf::Event& sfEvent)
{
	for (auto& gameObject : _gameObjects)
	{
		gameObject.HandleInput(sfEvent);
	}
}

void ArtaEngine::Scene::Draw(sf::RenderWindow& window)
{
	for (auto& gameObject : _gameObjects)
	{
		std::shared_ptr<SpriteRenderer> renderer = gameObject.GetComponent<SpriteRenderer>();

		if (renderer == nullptr)
			continue;

		window.draw(*renderer);
	}
}