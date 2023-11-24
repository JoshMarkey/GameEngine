#pragma once
#include <iostream>
#include <GameEngine/Core.h>
#include <GameEngine/TriangleRenderer.h>
#include <GameEngine/Cat.h>
#include <GameEngine/ModelRenderer.h>
#include "Map.h"
#undef main
using namespace myengine;

int main() 
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> player = core->addEntity();
	std::shared_ptr<Cat> cat = player->addComponent<Cat>();
	cat->player = true;
	player->addComponent<ModelRenderer>();
	player->addComponent<BoxCollider>()->setSize(glm::vec3(1.2, 3, 1.2));

	player->addComponent<RigidBody>();

	//create map entity with 'prefab' map component
	core->addEntity()->addComponent<Map>();


	core->run();

	return 0;
}