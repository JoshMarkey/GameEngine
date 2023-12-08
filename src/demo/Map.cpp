#include "Map.h"

using namespace myengine;

Map::Map()
{

}

void Map::onInitialise()
{
	std::shared_ptr<Entity> entity = getEntity();
	std::shared_ptr<ModelRenderer> model = entity->addComponent<ModelRenderer>();

	model->setModel("../Models/Map/Model.obj");
	model->setTexture("../Models/Map/Tex.png");

	//entity->addComponent<BoxCollider>()->setSize(glm::vec3(1.2, 3, 1.2));
	//entity->addComponent<RigidBody>();

	entity->transform->position = glm::vec3(0, -1.5, 0);

}
