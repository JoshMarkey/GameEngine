#pragma once
#include <iostream>
#include <GameEngine/Core.h>
#include <GameEngine/TriangleRenderer.h>
#include <GameEngine/Cat.h>
#include <GameEngine/Transform.h>
#include <GameEngine/Entity.h>
#include <GameEngine/ModelRenderer.h>
#include <GameEngine/BoxCollider.h>
#include <GameEngine/RigidBody.h>
#undef main
using namespace myengine;

int main() 
{
	std::shared_ptr<Core> core = Core::initialize();


	std::shared_ptr<Entity> entity = core->addEntity();
	std::shared_ptr<Transform> component2 = entity->addComponent<Transform>();
	std::shared_ptr<Cat> component3 = entity->addComponent<Cat>();
	std::shared_ptr<ModelRenderer> component4 = entity->addComponent<ModelRenderer>();
	entity->addComponent<BoxCollider>()->setSize(glm::vec3(1.2, 3, 1.2));
	entity->addComponent<RigidBody>();

	std::shared_ptr<Entity> entity2 = core->addEntity();
	entity2->addComponent<Transform>()->position = glm::vec3(2,0,0);
	std::shared_ptr<Cat> cat = entity2->addComponent<Cat>();
	cat->player = true;
	entity2->addComponent<ModelRenderer>();
	entity2->addComponent<BoxCollider>()->setSize(glm::vec3(1.2, 3, 1.2));

	entity2->addComponent<RigidBody>();
	

	core->run();

	return 0;
}