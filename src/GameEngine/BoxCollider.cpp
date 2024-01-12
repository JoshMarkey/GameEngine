#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"


namespace myengine
{



	void BoxCollider::onInitialise()
	{
		m_shape = new btBoxShape(btVector3(btScalar(2.0), btScalar(2.0), btScalar(2.0)));
		m_isStatic = false;
	}


}

