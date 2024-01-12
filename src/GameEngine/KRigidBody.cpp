#include "KRigidBody.h"
#include "Transform.h"
#include "Core.h"
#include "Entity.h"
namespace myengine
{
	void KRigidBody::onTick()
	{
		isColliding = false;
		getCore()->find<KCollider>(m_colliders);
		int selfIndex;
		bool collisionBool = false;
		float moveAmount = 0.5f;

		for (size_t i = 0; i < m_colliders.size(); i++)
		{
			if (m_colliders.at(i)->getEntity() == getEntity())
			{
				continue;
			}

			std::shared_ptr<KCollider> col = getEntity()->getComponent<KCollider>();

			if (col)
			{
				collisionBool = col->objectsColliding(m_colliders.at(i));
				if (collisionBool)
				{
					isColliding = true;
					col->CollisionResponse(col->getEntity(), m_colliders.at(i)->getEntity());
				}
			}
		}
		
		m_colliders.clear();
	}
	std::vector<std::shared_ptr<KCollider> > KRigidBody::getColliders()
	{
		return m_colliders;
	}
}

