#pragma once
#include "Component.h"
#include <stdexcept>
#include <vector>
#include <string>
#include "AudioSource.h"


namespace myengine
{
	struct SoundSource : Component
	{
	public:
		~SoundSource();
		void onTick() override;
		std::shared_ptr<AudioSource> sound;

		glm::vec3 lastPos{ 0 };
		void onInitialise() override;
		void setPath(std::string _path);
		void play();
	private:
		std::string path;

	};
}