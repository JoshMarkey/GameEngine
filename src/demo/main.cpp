#include <iostream>
#include <GameEngine/Core.h>
#include <GameEngine/TriangleRenderer.h>
#include <GameEngine/Cat.h>
#include <GameEngine/Transform.h>
#include <GameEngine/Entity.h>
#include <GameEngine/ModelRenderer.h>
#undef main
using namespace myengine;

int main() 
{
	std::shared_ptr<Core> core = Core::initialize();


	std::shared_ptr<Entity> entity = core->addEntity();
	//std::shared_ptr<TriangleRenderer> component = entity->addComponent<TriangleRenderer>();
	std::shared_ptr<Transform> component2 = entity->addComponent<Transform>();
	std::shared_ptr<Cat> component3 = entity->addComponent<Cat>();
	std::shared_ptr<ModelRenderer> component4 = entity->addComponent<ModelRenderer>();

	core->run();

	return 0;
}