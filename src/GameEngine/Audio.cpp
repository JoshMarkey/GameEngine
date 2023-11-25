#include "Audio.h"


namespace myengine
{
	myengine::Audio::~Audio()
	{
		if (m_context)
		{
			alcMakeContextCurrent(NULL);
			alcDestroyContext(m_context);
		}
		if (m_device)
		{
			alcCloseDevice(m_device);
		}
	}
}