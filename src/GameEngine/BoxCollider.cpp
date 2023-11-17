#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"

bool myengine::BoxCollider::colliding(std::shared_ptr<BoxCollider> _other)
{
	glm::vec3 a = getEntity()->transform->position;
	glm::vec3 b = _other->getEntity()->transform->position;
	glm::vec3 ahs = m_size / 2.0f;
	glm::vec3 bhs = _other->m_size / 2.0f;

	if (a.x > b.x)
	{
		if (b.x + bhs.x < a.x - ahs.x)
		{
			return false;
		}
	}
	else if (a.x + ahs.x < b.x - bhs.x)
	{
		return false;
	}

	if (a.y > b.y)
	{
		if (b.y + bhs.y < a.y - ahs.y)
		{
			return false;
		}
	}
	else if (a.y + ahs.y < b.y - bhs.y)
	{
		return false;
	}

	if (a.z > b.z)
	{
		if (b.z + bhs.z < a.z - ahs.z)
		{
			return false;
		}
	}
	else if (a.z + ahs.z < b.z - bhs.z)
	{
		return false;
	}

	return true;
}

void myengine::BoxCollider::setSize(glm::vec3 _s)
{
	m_size = _s;
}
