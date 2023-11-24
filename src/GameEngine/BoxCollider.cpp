#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"

bool myengine::BoxCollider::colliding(std::shared_ptr<BoxCollider> _other)
{
	glm::vec3 a = getEntity()->transform->position + m_offset;
	glm::vec3 b = _other->getEntity()->transform->position + _other->m_offset;
	glm::vec3 ahs = m_size / 2.0f;
	glm::vec3 bhs = _other->m_size / 2.0f;

	return checkCollision(a, b, ahs, bhs);	
}

bool myengine::BoxCollider::colliding(glm::vec3 position, glm::vec3 size)
{
	glm::vec3 a = getEntity()->transform->position + m_offset;

	return checkCollision(a, position, m_size / 2.0f, size / 2.0f);
}



void myengine::BoxCollider::setSize(glm::vec3 _s)
{
	m_size = _s;
}

bool myengine::BoxCollider::checkCollision(glm::vec3 a, glm::vec3 b, glm::vec3 ahs, glm::vec3 bhs)
{
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

glm::vec3 myengine::BoxCollider::getCollisionResponse(glm::vec3 position, glm::vec3 size)
{
	float amount = 0.05f;
	float step = 0.05f;
	while (true)
	{
		if (!colliding(position, size)) break;
		position.x += amount;
		if (!colliding(position, size)) break;
		position.x -= amount;
		position.x -= amount;
		if (!colliding(position, size)) break;
		position.x += amount;
		position.z += amount;
		if (!colliding(position, size)) break;
		position.z -= amount;
		position.z -= amount;
		if (!colliding(position, size)) break;
		position.z += amount;
		position.y += amount;
		if (!colliding(position, size)) break;
		position.y -= amount;
		position.y -= amount;
		if (!colliding(position, size)) break;
		position.y += amount;
		amount += step;
	}
	return position;
}


