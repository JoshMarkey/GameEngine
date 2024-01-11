#include "Component.h"
#include "Entity.h"
#include "Core.h"
#include "Enviroment.h"
#include "Gui.h"
#include "Transform.h"
namespace myengine
{
	std::shared_ptr<Entity> Component::getEntity()
	{
		return m_entity.lock();
	}
	glm::vec3 Component::getPosition()
	{
		return getEntity()->m_transform->getPosition();
	}
	void Component::onTick()
	{
	}
	void Component::onDisplay()
	{
	}
	void Component::onInitialise()
	{
	}
	void Component::onPhysicsTick()
	{

	}
	void Component::tick()
	{
		onTick();
	}
	void Component::onGui()
	{
	}
	void Component::onFrameEnd()
	{
	}
	int Component::getKey(int k)
	{
		return getCore()->getInput()->getKey(k);
	}
	int Component::getKeyUp(int k)
	{
		return getCore()->getInput()->getKeyUp(k);
	}
	int Component::getKeyDown(int k)
	{
		return getCore()->getInput()->getKeyDown(k);
	}
	glm::vec2 Component::getJoystickAxis()
	{
		return getCore()->getInput()->getJoystickAxis();
	}
	std::shared_ptr<Core> Component::getCore()
	{
		return m_entity.lock()->getCore();
	}
	std::shared_ptr<Gui> Component::getGui()
	{
		return getCore()->getGui();
	}
	std::shared_ptr<Physics> Component::getPhysics()
	{
		return getCore()->getPhysics();
	}
	float Component::DT()
	{
		return getCore()->getEnviroment()->DT();
	}
}