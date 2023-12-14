#include "RigidBody.h"
#include "Entity.h"
#include "Transform.h"
#include "BoxCollider.h"
#include "Core.h"

namespace myengine {
	void RigidBody::onTick()
	{
		
	}

	void RigidBody::setMass(float mass)
	{
		m_mass = mass;
	}
	void RigidBody::setSimulate(bool _sim)
	{
		simulate = _sim;
	}
	void RigidBody::onInitialise()
	{
		//Set up P-Transform
		m_trans.setIdentity();
		//Get col shape from col components
		std::shared_ptr<Collider> col = getEntity()->getComponent<Collider>();
		btCollisionShape* shape = col->m_shape;

		m_mass = 0;

		btVector3 localInertia(0, 0, 0);
		shape->calculateLocalInertia(m_mass, localInertia);

		//Set origin position from transform pos
		glm::vec3 position = getEntity()->transform->position;
		m_trans.setOrigin(btVector3(position.x, position.y, position.z));

		//using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
		btDefaultMotionState* myMotionState = new btDefaultMotionState(m_trans);
		btRigidBody::btRigidBodyConstructionInfo rbInfo(m_mass, myMotionState, shape, localInertia);
		m_body = new btRigidBody(rbInfo);
		//Add to physics
		getPhysics()->addObject(m_body);
	}

	void RigidBody::onPhysicsTick()
	{		
		m_trans = getPhysics()->getTransform(m_body);
		getEntity()->transform->position = glm::vec3(m_trans.getOrigin().getX(), m_trans.getOrigin().getY(), m_trans.getOrigin().getZ());

		glm::vec3 rot = glm::vec3(m_trans.getRotation().getX(), m_trans.getRotation().getY(), m_trans.getRotation().getZ());
		glm::quat q = rot;
		getEntity()->transform->rotation = glm::eulerAngles(q);
	}

	void RigidBody::onFrameEnd()
	{
		m_trans = getPhysics()->getTransform(m_body);

		glm::vec3 position = getEntity()->transform->position;
		glm::quat q = getEntity()->transform->rotation;

		m_trans.setOrigin(btVector3(position.x, position.y, position.z));
		btQuaternion quatonion;
		quatonion.setX(q.x);
		quatonion.setY(q.y);
		quatonion.setZ(q.z);
		m_trans.setRotation(quatonion);

		getPhysics()->setTransform(m_body, m_trans);
	}

	RigidBody::~RigidBody()
	{
		delete m_body;
	}
}
