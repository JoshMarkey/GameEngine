#include "SoundSource.h"
#include "Core.h"
#include "Resources.h"
#include "AudioSource.h"
//#include "Entity.h"
#include "Transform.h"

namespace myengine 
{
	SoundSource::~SoundSource()
	{
	}
	void SoundSource::onTick()
	{
		if (sound->getId());
		{
			glm::vec3 newPos = getEntity()->transform->position;
			if (newPos != lastPos)
			{
				alSource3f(sound->getId(), AL_POSITION, newPos.x, newPos.y, newPos.z);
				lastPos = newPos;
			}}
	}

	void SoundSource::onInitialise()
	{
		path = "../resources/Audio/dixie_horn.ogg";
	}
	
	void SoundSource::setPath(std::string _path)
	{
		path = _path;
	}

	void SoundSource::play()
	{
		std::shared_ptr<Core> core = getCore();
		std::shared_ptr<Resources> r = core->getResources();
		sound = r->load<AudioSource>(path);
		sound->play();
	}

	

}