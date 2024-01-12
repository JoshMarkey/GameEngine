#include "Camera.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"
namespace myengine
{
	//Create new View and Projection matrices each time to ensure they are always up to date
	glm::mat4 Camera::getProjection()
	{
		return glm::perspective(glm::radians(m_fov), m_aspect, m_nearPlane, m_farPlane);
	}
	
	glm::mat4 Camera::getView()
	{
		
		if (target != NULL)
		{
			targetPos = target->getPosition();
		}
		
		return glm::lookAt(getEntity()->getTransform()->getPosition(), targetPos, up);
	}

	void Camera::onInitialise()
	{
		first = true;
		m_fov = 45.0f;
		m_aspect = 1;
		m_nearPlane = 0.01;
		m_farPlane = 150;

		m_cameraAnglex = 0.0f;
		m_cameraAngley = 0.0f;

		m_speed = 5;
		m_mouseSpeed = 0.5f;
		targetPos = glm::vec3(5, 0.0f, -30);
		up = glm::vec3(0, 1, 0);

		getEntity()->getTransform()->setPosition(glm::vec3(4,5,15));
		getEntity()->getTransform()->rotate(glm::vec3(0,0,0));
	}
	void Camera::onTick()
	{
		
		if (target)
		{
			getEntity()->getTransform()->setPosition(glm::vec3(target->getPosition().x, target->getPosition().y + 4, target->getPosition().z + 15));
		}


		//This is for stopping the mouse tracking on the web build as it was really buggy
		//I have set up a different camera view which disables all camera movement
		//Not the most ideal solution, but it is there just to prove the web build works
#ifdef WIN32
		cameraFollowMouse();
#endif		
	}
	void Camera::setTarget(std::shared_ptr<Transform> _t)
	{
		target = _t;
	}

	// this is a free flying camera option the user can make use of if they like
	//Can be useful for debugging
	void Camera::cameraFollowMouse()
	{
		glm::vec2 win = getCore()->getWindowSize();
		m_cameraAnglex += (getCore()->getInput()->getMousePos().x - win.x/2)   * -m_mouseSpeed * DT();
		m_cameraAngley -= (getCore()->getInput()->getMousePos().y - win.y/2) * m_mouseSpeed * DT();

		//Calculate different directions for dynamic tranlation
		glm::vec3 direction(cos(m_cameraAngley) * sin(m_cameraAnglex), sin(m_cameraAngley), cos(m_cameraAngley) * cos(m_cameraAnglex));
		glm::vec3 right = glm::vec3(sin(m_cameraAnglex - 3.14f / 2.0f), 0, cos(m_cameraAnglex - 3.14f / 2.0f));
		up = glm::cross(right, direction);


		//Get both keyboard and controller input to control the camera

		glm::vec2 joystick = getJoystickAxis();

		// Move camera
		if (getKey(KeyCodes::w) || joystick.y < -0.1)
		{
			getEntity()->getTransform()->move(direction * m_speed * DT());

		}
		if (getKey(KeyCodes::s) || joystick.y > 0.1)
		{
			getEntity()->getTransform()->move(-direction * m_speed * DT());
		}
		if (getKey(KeyCodes::d) || joystick.x > 0.1)
		{
			getEntity()->getTransform()->move(right * m_speed * DT());

		}
		if (getKey(KeyCodes::a) || joystick.x < -0.1)
		{
			getEntity()->getTransform()->move(-right * m_speed * DT());
		}
		//update view matrix
		targetPos = getEntity()->getTransform()->getPosition() + direction;
	}
}