#pragma once
#include <AL/al.h>
#include <AL/alc.h>
#include <stdexcept>
#include <vector>
#include <string>

namespace myengine
{
	struct SoundSource
	{
	public:
		ALCdevice* device;
		ALCcontext* context;
		ALuint sourceId;
		~SoundSource();

		void init();
		void load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer, ALenum& _format, ALsizei& _freq);
	};
}