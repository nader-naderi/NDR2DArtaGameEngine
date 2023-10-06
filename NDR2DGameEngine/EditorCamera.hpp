#pragma once
#include <SFML/Graphics.hpp>

namespace ArtaEngine 
{
	class EditorCamera
	{
	public:
		EditorCamera() {}
		~EditorCamera() {}

	private:
		sf::Window* m_window;
		sf::View m_view;
	};
}

