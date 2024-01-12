#pragma once
#include <AL/al.h>
#include <AL/alc.h>
#include <iostream>
namespace myengine
{
	struct Core;
	//Simple struct to hold the AL init objs.
	struct Audio
	{
		~Audio();
	private:
		friend Core;
		ALCdevice* m_device;
		ALCcontext* m_context;
	};
}