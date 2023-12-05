#include "Component.h"
#include "Entity.h"
#include "Core.h"
#include "Enviroment.h"
#include "Gui.h"
namespace myengine
{
	std::shared_ptr<Entity> Component::getEntity()
	{
		return m_entity.lock();
	}
	void Component::onTick()
	{
	}
	void Component::onDisplay(std::shared_ptr<Entity> camera)
	{
	}
	void Component::onInitialise()
	{
	}
	void Component::tick()
	{
		onTick();
	}
	void Component::onGui()
	{
	}
	std::shared_ptr<Core> Component::getCore()
	{
		return m_entity.lock()->getCore();
	}
	std::shared_ptr<Gui> Component::getGui()
	{
		return getCore()->getGui();
	}
	float Component::DT()
	{
		return getCore()->getEnviroment()->DT();
	}
}