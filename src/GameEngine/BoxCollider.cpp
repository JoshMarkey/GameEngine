#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"


namespace myengine
{
	//Hard coded shape for the moment
	//This wasnt completed 100% and is still a work in progress
	void BoxCollider::onInitialise()
	{
		m_shape = new btBoxShape(btVector3(btScalar(2.0), btScalar(2.0), btScalar(2.0)));
		m_isStatic = false;
	}


}

