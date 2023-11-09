#include "GameObject.hpp"
#include "Component.hpp"
ArtaEngine::GameObject::GameObject(std::string name)
{
	this->_name = name;
	AddComponent(std::make_shared<Transform>());

	Initializers();
}

ArtaEngine::GameObject::GameObject()
{
	this->_name = "New GameObject";
	AddComponent(std::make_shared<Transform>());

	Initializers();
}

void ArtaEngine::GameObject::Initializers()
{
	for (auto& component : components)
	{
		std::cout << "iterating to init components \n";
		if (!component->IsActive())
		{
			std::cout << "Component of type: " << typeid(component).name() << " is not active, skipping it.\n";
			return;
		}

		component->Awake(); // Call Awake before Start
		component->Start(); // Call Start before Update
	}
}

void ArtaEngine::GameObject::Update(float deltaTime)
{
	for (auto& component : components)
	{
		if (!component->IsActive())
			return;

		component->Update(deltaTime);
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

	if (component->IsActive())
	{
		component->Awake(); // Call Awake before Start
		component->Start(); // Call Start before Update	
		//component->SetOwner(*this);
	}
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