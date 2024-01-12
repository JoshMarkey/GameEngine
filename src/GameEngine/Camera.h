#pragma once
#include "Component.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace myengine
{
	struct Transform;

	/*
	Camera holds the projection and viewing matrices
	It uses the entity's transform to get the position and rotation	
	*/
	struct Camera : Component
	{
	public:
		glm::mat4 getProjection();
		glm::mat4 getView();
		void onInitialise() override;
		void onTick() override;
		void setTarget(std::shared_ptr<Transform> _t); //If not in 1st person, set a target for the camera to follow
		std::shared_ptr<Transform> target;
		void cameraFollowMouse(); //Call on tick to make camera follow the mouse movement
		bool first;
		glm::vec3 targetPos;
	private:
		glm::vec3 up;
		float m_speed;
		float m_cameraAnglex;
		float m_cameraAngley;
		float m_mouseSpeed;
		float m_fov;
		float m_aspect;
		float m_farPlane;
		float m_nearPlane;
	};
}