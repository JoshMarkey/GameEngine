#include "RigidBody.h"
#include "Entity.h"
#include "Transform.h"
#include "BoxCollider.h"
#include "Core.h"

namespace myengine {

	void RigidBody::setMass(float mass)
	{
		m_mass = mass;
	}
	void RigidBody::init()
	{
		//Set up P-Transform
		m_trans.setIdentity();
		//Get col shape from col components
		m_collider = getEntity()->getComponent<Collider>();
		btCollisionShape* shape = m_collider->m_shape;

		//m_mass = 1;
		btVector3 localInertia(0, 0, 0);

		if (!m_collider->m_isStatic)
		{
			shape->calculateLocalInertia(m_mass, localInertia);
		}
		//Set origin position from transform pos
		glm::vec3 position = getEntity()->getTransform()->getPosition();
		m_trans.setOrigin(btVector3(position.x, position.y, position.z));

		//using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
		btDefaultMotionState* myMotionState = new btDefaultMotionState(m_trans);
		btRigidBody::btRigidBodyConstructionInfo rbInfo(m_mass, myMotionState, shape, localInertia);
		m_body = new btRigidBody(rbInfo);
		//Add to physics
		getPhysics()->addObject(m_body);
	}
	void RigidBody::setSimulate(bool _sim)
	{
		m_simulate = _sim;
	}

	void RigidBody::onPhysicsTick()
	{		
		m_trans = getPhysics()->getTransform(m_body);
		glm::vec3 pos = glm::vec3(m_trans.getOrigin().getX(), m_trans.getOrigin().getY(), m_trans.getOrigin().getZ());
		getEntity()->getTransform()->setPosition(pos);

		glm::vec3 rot = glm::vec3(m_trans.getRotation().getX(), m_trans.getRotation().getY(), m_trans.getRotation().getZ());
		glm::quat q = rot;
		getEntity()->getTransform()->setRotation(glm::eulerAngles(q));
	}

	void RigidBody::onFrameEnd()
	{
		if (!m_collider->m_isStatic)
		{
			m_trans = getPhysics()->getTransform(m_body);

			glm::vec3 position = getEntity()->getTransform()->getPosition();
			glm::quat q = getEntity()->getTransform()->getRotation();

			m_trans.setOrigin(btVector3(position.x, position.y, position.z));
			btQuaternion quatonion;
			quatonion.setX(q.x);
			quatonion.setY(q.y);
			quatonion.setZ(q.z);
			m_trans.setRotation(quatonion);

			getPhysics()->setTransform(m_body, m_trans);
		}
	}

	RigidBody::~RigidBody()
	{
		delete m_body;
	}
}
