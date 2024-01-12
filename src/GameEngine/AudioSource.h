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
	/*
	Audio resource loaded from .ogg files.
	Call play to play sound.
	Onload is called when the resource is created. Loads file and creates source & buffer
	*/
	struct AudioSource : Resource
	{
		void onLoad(std::string _path) override;
		void play();
		ALuint getId();
		~AudioSource();
	private:
		ALuint m_bufferId;
		ALuint m_sourceId;
		void load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer, 
			ALenum& _format, ALsizei& _freq);
	};
}