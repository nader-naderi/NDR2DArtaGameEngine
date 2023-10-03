#pragma once
#include <SFML/Graphics.hpp>

namespace ArtaEngine
{
	class State
	{
	protected:
		sf::View m_view;

	public:
		virtual void Init() = 0;

		virtual void HandleInput() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw(float dt) = 0;

		virtual void Pause() {}
		virtual void Resume() {}

		virtual sf::View& GetView()
		{
			return m_view;
		}
	};
}