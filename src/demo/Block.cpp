#include "Block.h"

void Block::onInitialise()
{
	model = getEntity()->addComponent<ModelRenderer>();
	model->setModel("../resources/Models/Block/Cube/Cube.obj");
	model->setTexture("../resources/Models/Block/Texture/GRASS.png");

	getEntity()->getTransform()->setScale(glm::vec3(1));
	std::shared_ptr<KCollider> col = getEntity()->addComponent<KCollider>();
	col->setColliderSize(glm::vec3(1));
}
