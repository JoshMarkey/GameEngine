#pragma once
#include "rend.h"
namespace graphics {
	struct Camera
	{
		Camera();
		glm::mat4 getView() { return m_view; }
		glm::mat4 getProjection() { return m_projection; }

	private:
		int m_posx;
		int m_posy;
		glm::mat4 m_projection;
		glm::mat4 m_view;
		glm::vec3 m_position;
		glm::mat4 m_rotation;
		float m_speed;
		float m_cameraAnglex;
		float m_cameraAngley;
		glm::vec3 m_translate;
	};

}