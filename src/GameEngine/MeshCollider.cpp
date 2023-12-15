#include "MeshCollider.h"
#include "Entity.h"
#include "Transform.h"


namespace myengine
{
	void MeshCollider::onInitialise()
	{
		m_shape = new btBvhTriangleMeshShape();
	}
}