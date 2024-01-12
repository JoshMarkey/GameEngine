#include "FloorPrefab.h"

void FloorPrefab::onInitialise()
{
	for (int x = 0; x < 10; x++)
	{
		for (int z = 0; z < 4; z++)
		{
			std::shared_ptr <Entity> entity = getCore()->addEntity();
			std::shared_ptr<Block> block = entity->addComponent<Block>();

			entity->getTransform()->setPosition(glm::vec3(x, 0, z));

			blocks.push_back(block);
		}
	}

	getCore()->getPrimaryCam()->setTarget(blocks[17]->getEntity()->getTransform());
}
