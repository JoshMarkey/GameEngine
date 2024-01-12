#include "Player.h"

using namespace myengine;

void Player::onInitialise()
{
	std::shared_ptr<ModelRenderer> model = getEntity()->addComponent<ModelRenderer>();
	model->setModel("../resources/Models/Cat/Model.obj");
	model->setTexture("../resources/Models/Cat/Tex.png");

	getEntity()->getTransform()->setPosition(glm::vec3(0, 2, 1));
	getEntity()->getTransform()->setRotation(glm::vec3(0, 90, 0));
	getEntity()->getTransform()->setScale(glm::vec3(0.6));

	std::shared_ptr<KCollider> col = getEntity()->addComponent<KCollider>();
	col->setColliderSize(glm::vec3(0.5,2.6,0.5));
	rb = getEntity()->addComponent<KRigidBody>();


	sound = getEntity()->addComponent<SoundSource>();
	sound->setPath("../resources/Audio/Jump.ogg");
	sound->setVol(1);

	accel = -1;
}

void Player::onTick()
{
	if (accel > -50)
	{
		accel -= 10 * DT();
	}

	bool isColliding = rb->isColliding;

	if (rb->isColliding)
	{

		if (getKey(KeyCodes::space) || getKey(KeyCodes::gpadA))
		{
			jump();
		}
	}
	else
	{
		getEntity()->getTransform()->move(glm::vec3(0, accel * DT(), 0));
	}
}

void Player::jump()
{
	sound->play();
	accel = 6.5;
	std::cout << "JUMP" << std::endl;
}
