#pragma once
#include "Component.h"
#include <glm/glm.hpp>

namespace myengine
{
	struct Transform : Component
	{
		Transform();
	public:
		void onFrameEnd() override;
		glm::mat4 getProjection();
		glm::mat4 getModel();
		void move(glm::vec3 pos);
		void rotate(glm::vec3 rot);
		glm::vec3 getPosition();
		glm::vec3 getRotation();
		glm::vec3 getScale();
		void setRotation(glm::vec3 _rot);
		void setPosition(glm::vec3 _pos);
		void setScale(glm::vec3 _scale);
		glm::vec3 getLastPos();
	private:
		glm::vec3 m_lastPosition;
		glm::vec3 m_position;
		glm::vec3 m_rotation;
		glm::vec3 m_scale;
	};
}