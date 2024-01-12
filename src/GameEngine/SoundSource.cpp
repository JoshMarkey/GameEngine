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
			}

			if (loop)
			{
				ALint state = 0;
				alGetSourcei(m_sound->getId(), AL_SOURCE_STATE, &state);
				if (state == AL_STOPPED)
				{
					play();
				}
			}
		}
	}

	void SoundSource::init()
	{
		std::shared_ptr<Core> core = getCore();
		std::shared_ptr<Resources> r = core->getResources();
		m_sound = r->load<AudioSource>(m_path);
	}

	void SoundSource::onInitialise()
	{
		m_path = "../resources/Audio/dixie_horn.ogg";
		loop = false;
	}
	
	void SoundSource::setPath(std::string _path)
	{
		m_path = _path;
		std::shared_ptr<Core> core = getCore();
		std::shared_ptr<Resources> r = core->getResources();
		m_sound = r->load<AudioSource>(m_path);
	}

	void SoundSource::play()
	{
		std::shared_ptr<Core> core = getCore();
		std::shared_ptr<Resources> r = core->getResources();
		m_sound = r->load<AudioSource>(m_path);
		m_sound->play();
	}

	void SoundSource::setVol(float v)
	{
		alSourcef(m_sound->getId(), AL_GAIN, v);
	}

	void SoundSource::setLoop(bool _b)
	{
		loop = _b;
	}

}