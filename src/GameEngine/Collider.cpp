#include "Collider.h"
#include "Entity.h"
#include "Transform.h"


namespace myengine
{
	void Collider::setSize(glm::vec3 _s)
	{
		m_size = _s;
	}

	Collider::~Collider()
	{
		delete m_shape;
	}
}