#pragma once
#include <SFML/Graphics.hpp>

namespace ArtaEngine
{
	class Component;
	class Transform;

	class GameObject
	{
	public:
		GameObject(std::string name);
		GameObject();
		~GameObject() {}

		void Initializers();
		void Update(float deltaTime);
		void HandleInput(sf::Event sfEvent);
		void Render(sf::RenderTarget& target, sf::RenderStates states);
		void AddComponent(std::shared_ptr<Component> component);
		
		void SetActive(bool isActive);
		bool IsActive() const;

		std::string GetName();
		
		template <typename T>
		std::shared_ptr<T> GetComponent();

		inline ArtaEngine::Transform& transform()
		{
			return *GetComponent<Transform>();
		}

	protected:
		std::string _name;

	private:
		std::vector <std::shared_ptr<Component>> components;
		bool isActive = true;
	};

	template<typename T>
	inline std::shared_ptr<T> GameObject::GetComponent()
	{
		for (const auto& component : components)
		{
			std::shared_ptr<T> castedComponent = std::dynamic_pointer_cast<T>(component);
			if (castedComponent)
				return castedComponent;
		}

		return nullptr;
	}
}

