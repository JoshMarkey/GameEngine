#pragma once
#include "Component.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace myengine
{
	struct Transform;

	struct Camera : Component
	{
	public:
		glm::mat4 getProjection();
		glm::mat4 getView();
		void onInitialise() override;
		void onTick() override;
		void setTarget(std::shared_ptr<Transform> _t);
		std::shared_ptr<Transform> target;
	private:
		float m_fov;
		float m_aspect;
		float m_farPlane;
		float m_nearPlane;
	};
}