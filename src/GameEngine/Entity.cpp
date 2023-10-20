#include "Entity.h"
#include "Component.h"
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


}