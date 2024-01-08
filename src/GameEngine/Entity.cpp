#include "Entity.h"
#include "Component.h"
#include "Transform.h"

namespace myengine
{
	myengine::Entity::Entity()
	{
		m_alive = true;
		
	}

	Entity::~Entity()
	{
	}

	void Entity::tick()
	{
		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			m_components.at(ci)->tick();
		}

	}

	void Entity::onGui()
	{
		for (int i = 0; i < m_components.size(); i++)
		{
			m_components[i].get()->onGui();
		}
	}

	void Entity::onFrameEnd()
	{
		for (int i = 0; i < m_components.size(); i++)
		{
			m_components[i].get()->onFrameEnd();
		}
	}

	void Entity::onPhysicsTick()
	{
		for (int i = 0; i < m_components.size(); i++)
		{
			m_components[i].get()->onPhysicsTick();
		}
	}

	bool Entity::alive()
	{
		return m_alive;
	}

	void Entity::display()
	{
		for (int i = 0; i < m_components.size(); i++)
		{
			m_components[i].get()->onDisplay();
		}
	}

	void Entity::kill()
	{
		if (!m_alive) return;
		m_alive = false;
		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			//m_components.at(ci)->kill();
		}
	}

	std::shared_ptr<Core> Entity::getCore()
	{
		return m_core;
	}


}