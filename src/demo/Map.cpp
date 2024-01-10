#include "Map.h"

using namespace myengine;

Map::Map()
{

}


void Map::onInitialise()
{
	std::shared_ptr<Entity> entity = getEntity();
	std::shared_ptr<ModelRenderer> model = entity->addComponent<ModelRenderer>();

	model->setModel("../resources/Models/Map/Model.obj");
	model->setTexture("../resources/Models/Map/Tex.png");

	entity->addComponent<MeshCollider>();
	std::shared_ptr<RigidBody> rb = getEntity()->addComponent<RigidBody>();
	rb->setMass(0);

	entity->transform->position = glm::vec3(0, -1.5, 0);
	rb->init();

}
