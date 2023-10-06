#include <iostream>
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "box2d/box2d.h"

int main()
{
	b2Vec2 gravity(0.0f, -9.8f);
	b2World world(gravity);


	ArtaEngine::Game(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	return EXIT_SUCCESS;
}