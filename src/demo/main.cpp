#include <iostream>
#include <GameEngine/Core.h>
#include <GameEngine/TriangleRenderer.h>
#include <GameEngine/Entity.h>
#undef main
using namespace myengine;

int main() 
{
	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Entity> entity = core->addEntity();
	std::shared_ptr<TriangleRenderer> component = entity->addComponent<TriangleRenderer>();

	return 0;
}