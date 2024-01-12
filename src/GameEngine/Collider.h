#pragma once
#include "Component.h"
#include "glm/glm.hpp"
#include <glm/ext.hpp>
#include "btBulletCollisionCommon.h"

namespace myengine
{
	/*
	Physics collider parent.
	Contains a shape which is the actual collider - to be set by child
	Can set offsets and size. As well as set if the collider is static
	*/
	struct Collider : Component
	{
	public:
		bool m_isStatic = false;
		void setSize(glm::vec3 _s);
		glm::vec3 getOffset() { return m_offset; }
		glm::vec3 getSize() { return m_size; }
		btCollisionShape* m_shape;
		~Collider();
	private:
		glm::vec3 m_size;
		glm::vec3 m_offset;

	
	};
}