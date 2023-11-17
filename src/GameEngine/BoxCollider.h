#pragma once
#include "Component.h"
#include "glm/glm.hpp"
#include <glm/ext.hpp>

namespace myengine
{
	struct BoxCollider : Component
	{
		bool colliding(std::shared_ptr<BoxCollider> _other);
		void setSize(glm::vec3 _s);

	private:
		glm::vec3 m_size;
		glm::vec3 m_offset;
		
		
	};
}