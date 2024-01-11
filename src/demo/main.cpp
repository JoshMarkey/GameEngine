#include <iostream>
#include "Map.h"
#include "GameEngine/PointLight.h"
#include <GameEngine/Cat.h>
#include <GameEngine/TriangleGui.h>
#undef main
using namespace myengine;

int main() 
{
	std::shared_ptr<Core> core = Core::initialise();

	std::shared_ptr<Entity> player = core->addEntity();
	std::shared_ptr<Cat> cat = player->addComponent<Cat>();
	cat->player = true;

	player->addComponent<TriangleGui>();

	//create map entity with 'prefab' map component
	core->addEntity()->addComponent<Map>();

	std::shared_ptr<Entity> light = core->addEntity();
	light->addComponent<PointLight>();


	core->run();

	return 0;
}