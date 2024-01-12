/*
Bullet Continuous Collision Detection and Physics Library
Copyright (c) 2003-2007 Erwin Coumans  http://continuousphysics.com/Bullet/

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it freely,
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/
#pragma once
#include "btBulletDynamicsCommon.h"
#include <stdio.h>
#include <memory>

namespace myengine
{
	struct Core;
	/*
	Contains all Bullet physics world logic
	*/
	struct Physics
	{
	public:
		void onTick();//Step physics world
		void initialise(std::shared_ptr<Core> _core);//Create a very simple dynamic world for colliders to be added
		void addObject(btRigidBody* _body);//Used inside rigid bodies to add the body to the world


		btTransform getTransform(btRigidBody* _body);//Returns the physics transform with updated position and rotation after the physics tick
		void setTransform(btRigidBody* _body, btTransform _trans);//This is used to inject non physics movement into physics world to kepp them synced
		~Physics();

	private:
		const float GRAVITY = -0.1;
		///collision configuration contains default setup for memory, collision setup. Advanced users can create their own configuration.
		btDefaultCollisionConfiguration* m_collisionConfiguration;

		///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
		btCollisionDispatcher* m_dispatcher;

		///btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
		btBroadphaseInterface* m_overlappingPairCache;

		///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
		btSequentialImpulseConstraintSolver* m_solver;

		//Physics world contains simulation
		btDiscreteDynamicsWorld* m_dynamicsWorld;

		//Different shape presets to be used
		btAlignedObjectArray<btCollisionShape*> m_collisionShapes;

		std::weak_ptr<Core> m_core;



		
	};
}