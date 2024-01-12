#include "Laser.h"
#include "GameManager.h"

using namespace myengine;

void Laser::onInitialise()
{
	std::shared_ptr<ModelRenderer> model = getEntity()->addComponent<ModelRenderer>();
	model->setModel("../resources/Models/Laser/Model.obj");
	model->setTexture("../resources/Models/Laser/Texture.png");

	getEntity()->getTransform()->setPosition(glm::vec3(11, 1.6, 1));
	getEntity()->getTransform()->setRotation(glm::vec3(0, 0, 0));
	getEntity()->getTransform()->setScale(glm::vec3(0.2));

	std::shared_ptr<KCollider> col = getEntity()->addComponent<KCollider>();
	std::shared_ptr<KRigidBody> rb = getEntity()->addComponent<KRigidBody>();
	col->setColliderSize(glm::vec3(0.3, 0.3, 5));
}

void Laser::onTick()
{
	if (getEntity()->getComponent<KRigidBody>()->isColliding)
	{
		//FAIL
		gameManager->isLaserAlive = false;
		getEntity()->setAlive(false);
		std::cout << "FAIL" << std::endl;
	}
	else if (getEntity()->getTransform()->getPosition().x < 0)
	{
		//PASS
		gameManager->isLaserAlive = false;
		getEntity()->setAlive(false);
		std::cout << "PASS" << std::endl;
	}

	getEntity()->getTransform()->move(glm::vec3(-speed * DT(), 0, 0));

}

void Laser::init(std::shared_ptr<GameManager> _gm, float _speed)
{
	gameManager = _gm;
	speed = _speed;
}

