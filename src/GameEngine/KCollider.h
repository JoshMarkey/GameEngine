#pragma once
#include "Component.h"

namespace myengine
{
	/*
	Used to be Kludge, is now a slightly more consistent method
	Still includes Kludge as in some cases it is more effective
	Saves last position so when it detects a collision, it reverts back
	The collider shape is a simple box
	This was left in as physic didnt work properly. Physics code is still included as a work in progress
	*/
	struct KCollider : Component
	{
		KCollider();

		bool objectsColliding(std::shared_ptr<KCollider> _other);//Kludge
		bool objectsColliding(glm::vec3 _position, glm::vec3 _size);//reverting method
		bool CollisionCheck(glm::vec3 _a, glm::vec3 _b, glm::vec3 _ahs, glm::vec3 _bhs); //Returns true if there is a collision

		glm::vec3 CollisionResponse(glm::vec3 _position, glm::vec3 _size);
		void CollisionResponse(std::shared_ptr<Entity> _self, std::shared_ptr<Entity> _other);

		glm::vec3 getSize() { return m_size; }
		void setColliderSize(glm::vec3 _size) { m_size = _size; } //Scale box

		glm::vec3 getOffset() { return m_offset; }
		void setOffset(glm::vec3 _offset) { m_offset = _offset; } //Offset the position from the transform

	private:
		glm::vec3 m_size;
		glm::vec3 m_offset;
	};
}