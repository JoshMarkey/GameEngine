#include "Physics.h"
#include "Core.h"
#include "Enviroment.h"

namespace myengine
{
	void Physics::initialise(std::shared_ptr<Core> core)
	{
		m_core = core;

		m_collisionConfiguration = new btDefaultCollisionConfiguration();

		///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
		m_dispatcher = new btCollisionDispatcher(m_collisionConfiguration);

		///btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
		m_overlappingPairCache = new btDbvtBroadphase();

		///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
		m_solver = new btSequentialImpulseConstraintSolver;

		m_dynamicsWorld = new btDiscreteDynamicsWorld(m_dispatcher, m_overlappingPairCache, m_solver, m_collisionConfiguration);

		m_dynamicsWorld->setGravity(btVector3(0, GRAVITY, 0));

	}


	Physics::~Physics()
	{
		for (int i = m_dynamicsWorld->getNumCollisionObjects() - 1; i >= 0; i--)
		{
			btCollisionObject* obj = m_dynamicsWorld->getCollisionObjectArray()[i];
			btRigidBody* body = btRigidBody::upcast(obj);
			if (body && body->getMotionState())
			{
				delete body->getMotionState();
			}
			m_dynamicsWorld->removeCollisionObject(obj);
			delete obj;
		}

		//delete collision shapes
		for (int j = 0; j < m_collisionShapes.size(); j++)
		{
			btCollisionShape* shape = m_collisionShapes[j];
			m_collisionShapes[j] = 0;
			delete shape;
		}

		//delete dynamics world
		delete m_dynamicsWorld;

		//delete solver
		delete m_solver;

		//delete broadphase
		delete m_overlappingPairCache;

		//delete dispatcher
		delete m_dispatcher;

		delete m_collisionConfiguration;
	}

	void Physics::addObject(btRigidBody* body)
	{
		m_dynamicsWorld->addRigidBody(body);
	}

	void Physics::onTick()
	{
		m_dynamicsWorld->stepSimulation(m_core.lock()->getEnviroment()->DT());
	}

	btTransform Physics::getTransform(btRigidBody* body)
	{
		btTransform rtn;
		body->getMotionState()->getWorldTransform(rtn);
		return rtn;
	}

	void Physics::setTransform(btRigidBody* body, btTransform trans)
	{
		body->getMotionState()->setWorldTransform(trans);
	}
}