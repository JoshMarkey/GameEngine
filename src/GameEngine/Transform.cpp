#include "Transform.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <iostream>

namespace myengine {
	Transform::Transform()
	{
		position = glm::vec3(0);
		rotation = glm::vec3(0);
		rotmat = glm::mat4(1);
	}

	glm::mat4 Transform::getProjection()
	{
		return glm::translate(rotmat,position);
	}

	glm::mat4 Transform::getModel()
	{
		return glm::mat4(1);
	}
	void Transform::rotate(float angle, glm::vec3 rot)
	{
		rotmat = glm::rotate(rotmat, glm::radians(angle), rot);
	}
}