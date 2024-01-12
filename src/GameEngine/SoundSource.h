#pragma once
#include "Component.h"
#include <stdexcept>
#include <vector>
#include <string>
#include "AudioSource.h"


namespace myengine
{
	/*
	Wrapper for sound resource
	*/
	struct SoundSource : Component
	{
	public:
		~SoundSource();
		void onTick() override;//Check for looping and move positions

		void init();
		void setVol(float v);//Set gain inside the sound source
		void setLoop(bool _b);//Set to tru to loop audio
		glm::vec3 lastPos{ 0 };
		void onInitialise() override;//Set default path to error handle
		void setPath(std::string _path);//Change file path
		void play();
	private:
		std::string m_path;
		bool loop;
		std::shared_ptr<AudioSource> m_sound;

	};
}