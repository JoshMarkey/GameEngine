#include "Component.h"
#include "Entity.h"
#include "Core.h"
#include "Enviroment.h"
namespace myengine
{
	std::shared_ptr<Entity> Component::getEntity()
	{
		return m_entity.lock();
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
	void Component::tick()
	{
		onTick();
	}
	std::shared_ptr<Core> Component::getCore()
	{
		return m_entity.lock()->getCore();
	}
	float Component::DT()
	{
		return getCore()->getEnviroment()->DT();
	}
}