#pragma once
#include "Component.h"
#include "glm/glm.hpp"
#include <glm/ext.hpp>
#include "btBulletCollisionCommon.h"

namespace myengine
{
	struct Collider : Component
	{

	private:
		glm::vec3 m_size;
		glm::vec3 m_offset;

	public:
		void setSize(glm::vec3 _s);
		glm::vec3 getOffset() { return m_offset; }
		glm::vec3 getSize() { return m_size; }
		btCollisionShape* m_shape;
		~Collider();
	};
}