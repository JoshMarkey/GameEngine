#pragma once
#include <memory>
#include "Resource.h"
#include <AL/al.h>
#include <AL/alc.h>
#include <stdexcept>
#include <vector>
#include <string>

namespace myengine
{
	struct AudioSource : Resource
	{
		void onLoad(std::string _path) override;
		void play();
		~AudioSource();
		ALuint getId();
	private:
		ALuint bufferId;
		ALuint sourceId;
		void load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer, 
			ALenum& _format, ALsizei& _freq);
	};
}