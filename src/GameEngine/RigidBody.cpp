#include "RigidBody.h"
#include "Entity.h"
#include "Transform.h"
#include "BoxCollider.h"
#include "Core.h"

namespace myengine {
	void RigidBody::onTick()
	{
		std::vector<std::shared_ptr<BoxCollider> > colliders;
		getCore()->find<BoxCollider>(colliders);

		std::shared_ptr<BoxCollider> self = getEntity()->getComponent<BoxCollider>();

		for (size_t c = 0; c < colliders.size(); ++c)
		{
			if (colliders.at(c) != self)
			{
				if (self->colliding(colliders.at(c)))
				{
					colliders.at(c)->getEntity()->transform->position = 
						self->getCollisionResponse(colliders.at(c)->getEntity()->transform->position + colliders.at(c)->getOffset(),
						colliders.at(c)->getSize());

					//std::cout << "ADFGADFH" << std::endl;
				}
			}
		}
	}
}
