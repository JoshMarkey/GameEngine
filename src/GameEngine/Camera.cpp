#include "Camera.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"
namespace myengine
{
	glm::mat4 Camera::getProjection()
	{
		return glm::perspective(glm::radians(fov), aspect, nearPlane, farPlane);
	}

	glm::mat4 Camera::getView()
	{
		glm::vec3 targetPos = glm::vec3(5, 0.0f, -30);
		if (target != NULL)
		{
			targetPos = target->position;
		}
		
		return glm::lookAt(getEntity()->transform->position, targetPos, glm::vec3(0, 1, 0));
	}
	void Camera::onInitialise()
	{
		fov = 45;
		aspect = 1;
		nearPlane = 0.01;
		farPlane = 150;
	}
	void Camera::onTick()
	{
		if (target)
		{
			getEntity()->transform->position = glm::vec3(target->position.x, target->position.y + 4, target->position.z + 15);
		}

		/*
		std::shared_ptr<Entity> entity = getEntity();
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
		} */
	}
	void Camera::setTarget(std::shared_ptr<Transform> _t)
	{
		target = _t;
	}
}