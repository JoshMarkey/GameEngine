#include "Transform.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <iostream>

namespace myengine {
	Transform::Transform()
	{
		m_position = glm::vec3(0);
		m_rotation = glm::vec3(0);
		m_scale = glm::vec3(1);
	}

	void Transform::onFrameEnd()
	{
		m_lastPosition = m_position;
	}

	glm::mat4 Transform::getModel()
	{
		glm::mat4 rtn = glm::translate(glm::mat4(1), m_position);

		rtn = glm::rotate(rtn, glm::radians(m_rotation.x), glm::vec3(1, 0, 0));
		rtn = glm::rotate(rtn, glm::radians(m_rotation.y), glm::vec3(0, 1, 0));
		rtn = glm::rotate(rtn, glm::radians(m_rotation.z), glm::vec3(0, 0, 1));

		rtn = glm::scale(rtn, m_scale);

		return rtn;
	}

	void Transform::move(glm::vec3 pos)
	{
		m_position += pos;
	}

	void Transform::rotate(glm::vec3 rot)
	{
		m_rotation += rot;
	}
	glm::vec3 Transform::getPosition()
	{
		return m_position;
	}
	glm::vec3 Transform::getRotation()
	{
		return m_rotation;
	}
	glm::vec3 Transform::getScale()
	{
		return m_scale;
	}
	void Transform::setRotation(glm::vec3 _rot)
	{
		m_rotation = _rot;
	}
	void Transform::setPosition(glm::vec3 _pos)
	{
		m_position = _pos;
	}
	void Transform::setScale(glm::vec3 _scale)
	{
		m_scale = _scale;
	}
	glm::vec3 Transform::getLastPos()
	{
		return m_lastPosition;
	}
}
