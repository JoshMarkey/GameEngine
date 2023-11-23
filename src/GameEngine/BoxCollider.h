#pragma once
#include "Component.h"
#include "glm/glm.hpp"
#include <glm/ext.hpp>

namespace myengine
{
	struct BoxCollider : Component
	{
		bool colliding(std::shared_ptr<BoxCollider> _other);
		bool colliding(glm::vec3 position, glm::vec3 size);
		
		void setSize(glm::vec3 _s);
		glm::vec3 getCollisionResponse(glm::vec3 position, glm::vec3 size);
		glm::vec3 getOffset() { return m_offset; }
		glm::vec3 getSize() { return m_size; }
	private:
		bool checkCollision(glm::vec3 a, glm::vec3 b, glm::vec3 ahs, glm::vec3 bhs);
		glm::vec3 m_size;
		glm::vec3 m_offset;
		
		
	};
}