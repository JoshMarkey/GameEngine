#include "Physics.h"
#include "Core.h"
#include "Enviroment.h"

namespace myengine
{
	void Physics::Init(std::shared_ptr<Core> core)
	{
		m_core = core;

		collisionConfiguration = new btDefaultCollisionConfiguration();

		///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
		dispatcher = new btCollisionDispatcher(collisionConfiguration);

		///btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
		overlappingPairCache = new btDbvtBroadphase();

		///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
		solver = new btSequentialImpulseConstraintSolver;

		dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);

		dynamicsWorld->setGravity(btVector3(0, GRAVITY, 0));
	}


	Physics::~Physics()
	{
		for (int i = dynamicsWorld->getNumCollisionObjects() - 1; i >= 0; i--)
		{
			btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[i];
			btRigidBody* body = btRigidBody::upcast(obj);
			if (body && body->getMotionState())
			{
				delete body->getMotionState();
			}
			dynamicsWorld->removeCollisionObject(obj);
			delete obj;
		}

		//delete collision shapes
		for (int j = 0; j < collisionShapes.size(); j++)
		{
			btCollisionShape* shape = collisionShapes[j];
			collisionShapes[j] = 0;
			delete shape;
		}

		//delete dynamics world
		delete dynamicsWorld;

		//delete solver
		delete solver;

		//delete broadphase
		delete overlappingPairCache;

		//delete dispatcher
		delete dispatcher;

		delete collisionConfiguration;
	}

	void Physics::addObject(btRigidBody* body)
	{
		dynamicsWorld->addRigidBody(body);
	}

	void Physics::tick()
	{
		//m_core.lock()->getEnviroment()->DT()
		dynamicsWorld->stepSimulation(0, 10);
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