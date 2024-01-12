#include "KCollider.h"
#include "Entity.h"
#include "Transform.h"

namespace myengine
{
	KCollider::KCollider()
	{
	}

	bool KCollider::objectsColliding(std::shared_ptr<KCollider> _other)
	{
		glm::vec3 a = getEntity()->getTransform()->getPosition();
		glm::vec3 b = _other->getEntity()->getTransform()->getPosition();
		glm::vec3 ahs = m_size / 2.0f;
		glm::vec3 bhs = _other->m_size / 2.0f;

		return CollisionCheck(a, b, ahs, bhs);
	}

	bool KCollider::objectsColliding(glm::vec3 _position, glm::vec3 _size)
	{
		glm::vec3 a = getEntity()->getTransform()->getPosition();
		glm::vec3 b = _position;
		glm::vec3 ahs = m_size / 2.0f;
		glm::vec3 bhs = _size / 2.0f;

		return CollisionCheck(a, b, ahs, bhs);
	}
	//Kludge method
	bool KCollider::CollisionCheck(glm::vec3 _a, glm::vec3 _b, glm::vec3 _ahs, glm::vec3 _bhs)
	{
		if (_a.x > _b.x)
		{
			if (_b.x + _bhs.x < _a.x - _ahs.x)
			{
				return false;
			}
		}
		else
		{
			if (_a.x + _ahs.x < _b.x - _bhs.x)
			{
				return false;
			}
		}

		if (_a.y > _b.y)
		{
			if (_b.y + _bhs.y < _a.y - _ahs.y)
			{
				return false;
			}
		}
		else
		{
			if (_a.y + _ahs.y < _b.y - _bhs.y)
			{
				return false;
			}
		}

		if (_a.z > _b.z)
		{
			if (_b.z + _bhs.z < _a.z - _ahs.z)
			{
				return false;
			}
		}
		else
		{
			if (_a.z + _ahs.z < _b.z - _bhs.z)
			{
				return false;
			}
		}

		return true;
	}

	glm::vec3 KCollider::CollisionResponse(glm::vec3 _position, glm::vec3 _size)
	{
		glm::vec3 originalPos = _position;
		float increase = 0.001f;
		float step = 0.001f;
		bool iterating = true;

		while (iterating)
		{
			if (!objectsColliding(_position, _size))
			{
				break;
			}
			_position.x += increase;

			if (!objectsColliding(_position, _size))
			{
				break;
			}
			_position.x -= increase;
			_position.x -= increase;

			if (!objectsColliding(_position, _size))
			{
				break;
			}
			_position.x += increase;
			_position.z += increase;

			if (!objectsColliding(_position, _size))
			{
				break;
			}
			_position.z -= increase;
			_position.z -= increase;

			if (!objectsColliding(_position, _size))
			{
				break;
			}
			_position.z += increase;
			_position.y += increase;

			if (!objectsColliding(_position, _size))
			{
				break;
			}
			_position.y -= increase;
			_position.y -= increase;

			if (!objectsColliding(_position, _size))
			{
				break;
			}
			_position.y += increase;
			increase += step;

		}

		return _position;
	}

	void KCollider::CollisionResponse(std::shared_ptr<Entity> _self, std::shared_ptr<Entity> _other)
	{
		_self->getTransform()->setPosition(_self->getTransform()->getLastPos());
		_other->getTransform()->setPosition(_other->getTransform()->getLastPos());
	}


}

