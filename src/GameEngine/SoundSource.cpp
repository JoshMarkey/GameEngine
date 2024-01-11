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
		if (m_sound->getId());
		{
			glm::vec3 newPos = getEntity()->m_transform->getPosition();
			if (newPos != lastPos)
			{
				alSource3f(m_sound->getId(), AL_POSITION, newPos.x, newPos.y, newPos.z);
				lastPos = newPos;
			}}
	}

	void SoundSource::onInitialise()
	{
		m_path = "../resources/Audio/dixie_horn.ogg";
	}
	
	void SoundSource::setPath(std::string _path)
	{
		m_path = _path;
	}

	void SoundSource::play()
	{
		std::shared_ptr<Core> core = getCore();
		std::shared_ptr<Resources> r = core->getResources();
		m_sound = r->load<AudioSource>(m_path);
		m_sound->play();
	}

	

}