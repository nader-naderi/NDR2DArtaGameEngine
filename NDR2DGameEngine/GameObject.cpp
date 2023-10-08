#include "GameObject.hpp"

ArtaEngine::GameObject::GameObject()
{
	this->_name = "New GameObject";
	AddComponent(std::make_shared<Transform>());
}

void ArtaEngine::GameObject::Update(float deltaTime)
{
	for (auto& component : components)
	{
		if (!component->IsActive())
			return;

		component->Update();
	}
}

void ArtaEngine::GameObject::HandleInput(sf::Event sfEvent)
{
	
	switch (sfEvent.type)
	{
	case sf::Event::KeyPressed:
		// Handle key presses
		if (sfEvent.key.code == sf::Keyboard::Left)
		{
			// Respond to the left arrow key press
			// You can add your custom logic here
		}
		// Add more cases for other key presses as needed
		break;

	case sf::Event::MouseButtonPressed:
		// Handle mouse button presses
		if (sfEvent.mouseButton.button == sf::Mouse::Left)
		{
			// Respond to the left mouse button click
			// You can add your custom logic here
		}
		// Add more cases for other mouse button presses as needed
		break;

		// Handle other types of events here as needed

	default:
		break;
	}
}

void ArtaEngine::GameObject::Render(sf::RenderTarget& target, sf::RenderStates states)
{
	for (auto& component : components)
	{
		if (!component->IsActive())
			return;

		component->Render(target);
	}
}

void ArtaEngine::GameObject::AddComponent(std::shared_ptr<Component> component)
{
	components.push_back(component);
	component->SetOwner(this);
}

void ArtaEngine::GameObject::SetActive(bool isActive)
{
	this->isActive = isActive;
}

bool ArtaEngine::GameObject::IsActive() const
{
	return this->isActive;
}

std::string ArtaEngine::GameObject::GetName()
{
	return _name;
}

ArtaEngine::Transform& ArtaEngine::GameObject::transform()
{
	return *GetComponent<Transform>();
}
