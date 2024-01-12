#include <iostream>
#include "Map.h"
#include "GameEngine/PointLight.h"
#include <GameEngine/TriangleGui.h>
#include "GameManager.h"
#undef main
using namespace myengine;

int main() 
{
	std::shared_ptr<Core> core = Core::initialise();

	//Controls whole game
	std::shared_ptr<Entity> game = core->addEntity();
	std::shared_ptr<GameManager> gameManager = game->addComponent<GameManager>();



	core->run();

	return 0;
}