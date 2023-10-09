#include "Game.hpp"
#include "GameObject.hpp"
#include "Component.hpp"

#ifndef ARTA_BEHAVIOUR
#define ARTA_BEHVAIOUR

namespace ArtaEngine
{
	class ArtaBehaviour : public Component
	{
	public:
		ArtaEngine::GameObject* GetGameObject()
		{
			return this->gameObject;
		}

	private:
		ArtaEngine::GameObject* gameObject;

	};
}

#endif // ARTA_BEHAVIOUR
