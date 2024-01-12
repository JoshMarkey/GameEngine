#include "Entity.h"
#include "AudioListener.h"
#include "Transform.h"
#include <AL/al.h>

void myengine::AudioListener::onTick()
{
	//Move listener to transform position for direction audio
	glm::vec3 newPos = getEntity()->getTransform()->getPosition();
	if (newPos != lastPos)
	{
		alListener3f(AL_POSITION, newPos.x, newPos.y, newPos.z);
		lastPos = newPos;
	}
}
