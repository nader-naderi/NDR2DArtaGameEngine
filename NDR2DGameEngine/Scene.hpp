#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"

namespace ArtaEngine 
{
	class Scene
	{
	public:
		Scene(GameDataRef data) {}
		virtual ~Scene() {}

		virtual void Init() {}
		virtual void Update(float dt) {}
		virtual void Draw() {}

	private:
		GameDataRef data;
	};
}
