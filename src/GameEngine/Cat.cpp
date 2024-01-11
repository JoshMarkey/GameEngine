#include "Cat.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"
#include "Enviroment.h"
#include "AudioSource.h"
#include "Camera.h"
#include "BoxCollider.h"
#include "RigidBody.h"
#include "SoundSource.h"
#include "ModelRenderer.h"
#include "AudioListener.h"

namespace myengine
{
	Cat::Cat()
	{
	}
	Cat::~Cat()
	{
	}

	void Cat::onTick()
	{
		float speed = 10;
		if (player)
		{
			std::shared_ptr<Entity> entity = m_entity.lock();
			angle = 360 * DT();
			//std::cout << angle << std::endl;
			entity->m_transform->rotate(glm::vec3(0, angle, 0));
			if (angle > 360)
			{
				angle -= 360;
			}
			glm::vec2 joystick = getJoystickAxis();
			
			if (getKey(KeyCodes::d) || joystick.x > 0.1)
			{
				entity->m_transform->move(glm::vec3(speed, 0, 0) * DT());
			}
			if (getKey(KeyCodes::a) || joystick.x < -0.1)
			{
				entity->m_transform->move(glm::vec3(-speed, 0, 0) * DT());
			}
			if (getKey(KeyCodes::w )|| joystick.y < -0.1)
			{
				entity->m_transform->move(glm::vec3(0, 0, -speed) * DT());
			}
			if (getKey(KeyCodes::s) || joystick.y > 0.1)
			{
				entity->m_transform->move(glm::vec3(0, 0, speed) * DT());
			}
		}
	}
	void Cat::onInitialise()
	{
		
		getEntity()->addComponent<AudioListener>();
		getEntity()->addComponent<SoundSource>()->play();
		getEntity()->addComponent<ModelRenderer>();
		getEntity()->addComponent<BoxCollider>();
		std::shared_ptr<RigidBody> rb = getEntity()->addComponent<RigidBody>();
		rb->setMass(1.0f);
		rb->setSimulate(true);
		rb->init();

		m_entity.lock()->m_transform->move(glm::vec3(0, -0, -14));
		getCore()->getPrimaryCam()->setTarget(getEntity()->m_transform);
	}
}