#pragma once
#include "Component.h"
#include <stdexcept>
#include <vector>
#include <string>


namespace myengine
{
	struct SoundSource : Component
	{
	public:
		~SoundSource();

		void onInitialise() override;
		void setPath(std::string _path);
		void play();
	private:
		std::string path;

	};
}