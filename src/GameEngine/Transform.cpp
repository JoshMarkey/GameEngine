#include "Transform.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <iostream>

namespace myengine {
	Transform::Transform()
	{
		position = glm::vec3(0);
		rotation = glm::vec3(0);
		scale = glm::vec3(1);
	}

	glm::mat4 Transform::getProjection()
	{
		return glm::perspective(glm::radians(45.0f), 1.0f, 0.01f, 150.0f);
	}

	glm::mat4 Transform::getModel()
	{
		glm::mat4 rtn = glm::translate(glm::mat4(1), position);

		rtn = glm::rotate(rtn, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		rtn = glm::rotate(rtn, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		rtn = glm::rotate(rtn, glm::radians(rotation.z), glm::vec3(0, 0, 1));

		rtn = glm::scale(rtn, scale);

		return rtn;
	}

	void Transform::move(glm::vec3 pos)
	{
		position += pos;
	}

	void Transform::rotate(glm::vec3 rot)
	{
		rotation += rot;
	}
}