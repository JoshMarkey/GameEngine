#include "Camera.h"


Camera::Camera()
{
	m_position = glm::vec3(5, 3,-30);
	glm::vec3 initTarget = glm::vec3(5, 0.0f, -30);

	m_cameraAnglex = 0.0f;
	m_cameraAngley = 0.0f;



	//Create matrix
	m_projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.01f, 150.0f);
	m_view = glm::lookAt(m_position, initTarget, glm::vec3(0,1,0));
}
