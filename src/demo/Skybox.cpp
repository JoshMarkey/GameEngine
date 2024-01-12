#include "Skybox.h"

void Skybox::onInitialise()
{
	std::shared_ptr<ModelRenderer> model = getEntity()->addComponent<ModelRenderer>();
	model->setModel("../resources/Models/SkyBox/Cube.obj");
	model->setTexture("../resources/Models/SkyBox/night.png");
	model->setBackFace(false);
	
	getEntity()->getTransform()->setScale(glm::vec3(50, 50, 50));
	getEntity()->getTransform()->setPosition(glm::vec3(0, 0, 0));
}
