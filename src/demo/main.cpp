#include <iostream>
#include <GameEngine/Core.h>
#undef main
using namespace myengine;

int main() 
{
	std::shared_ptr<Core> core = Core::initialize();
	//std::shared_ptr<Entity> entity = core->addEntity();
	//std::shared_ptr<Component> component = entity->addComponent();

	return 0;
}