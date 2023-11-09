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

		void Update(float dt) override
		{
			this->deltaTime = dt;
		}

	protected:
		float deltaTime;
	};
}

#endif // ARTA_BEHAVIOUR
