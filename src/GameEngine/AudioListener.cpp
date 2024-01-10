#include "Entity.h"
#include "AudioListener.h"
#include "Transform.h"
#include <AL/al.h>

void myengine::AudioListener::onTick()
{
	glm::vec3 newPos = getEntity()->transform->position;
	if (newPos != lastPos)
	{
		alListener3f(AL_POSITION, newPos.x, newPos.y, newPos.z);
		lastPos = newPos;
	}
}
