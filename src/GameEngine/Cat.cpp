#include "Cat.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"
#include "Enviroment.h"
#include "AudioSource.h"
#include "Camera.h"

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
		if (player)
		{
			std::shared_ptr<Entity> entity = m_entity.lock();
			angle = 360 * DT();
			//std::cout << angle << std::endl;
			entity->transform->rotate(glm::vec3(0, angle, 0));
			if (angle > 360)
			{
				angle -= 360;
			}
			
			if (getCore()->getInput()->getKey(KeyCodes::d))
			{
				entity->transform->move(glm::vec3(10, 0, 0) * DT());
			}
			if (getCore()->getInput()->getKey(KeyCodes::a))
			{
				entity->transform->move(glm::vec3(-10, 0, 0) * DT());
			}
			if (getCore()->getInput()->getKey(KeyCodes::w))
			{
				entity->transform->move(glm::vec3(0, 0, -10) * DT());
			}
			if (getCore()->getInput()->getKey(KeyCodes::s))
			{
				entity->transform->move(glm::vec3(0, 0, 10) * DT());
			}
			
		}
	}
	void Cat::onInitialise()
	{
		//getCore()->getResources()->load<AudioSource>("../Audio/dixie_horn.ogg");
		
		m_entity.lock()->transform->move(glm::vec3(0, -1.5, -14));
		getCore()->camera->getComponent<Camera>()->setTarget(getEntity()->transform);
	}
}