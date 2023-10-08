#pragma once
#include <SFML/Graphics.hpp>
#include "Component.hpp"

// TODO: Create Components and add them to the gameobejcts. (Transform, SpriteRenderer, Rigidbody, CustomScriptBehaviour, etc. )
namespace ArtaEngine
{
	class GameObject : public sf::Transformable, public sf::Drawable
	{
	public:
		GameObject();
		~GameObject() {}

		void Update(float deltaTime);
		void HandleInput(sf::Event sfEvent);
		void Render(sf::RenderTarget& target, sf::RenderStates states);
		void AddComponent(std::shared_ptr<Component> component);
		
		void SetActive(bool isActive);
		bool IsActive() const;

		std::string GetName();
		
		template <typename T>
		std::shared_ptr<T> GetComponent();

		Transform& transform();

	protected:
		std::string _name;

	private:
		std::vector < std::shared_ptr<Component>> components;
		bool isActive;
	};

	template<typename T>
	inline std::shared_ptr<T> GameObject::GetComponent()
	{
		for (const auto& component : components)
		{
			std::shared_ptr<T> castedComponent = std::dynamic_pointer_cast<T>;
			if (castedComponent)
				return castedComponent;
		}

		return nullptr;
	}
}