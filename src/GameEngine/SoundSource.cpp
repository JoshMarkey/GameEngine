#pragma once
#include "SoundSource.h"
#include "Core.h"
#include "Resources.h"
#include "AudioSource.h"

namespace myengine 
{
	SoundSource::~SoundSource()
	{
	}
	void SoundSource::onInitialise()
	{
		path = "../Audio/dixie_horn.ogg";
	}
	
	void SoundSource::setPath(std::string _path)
	{
		path = _path;
	}

	void SoundSource::play()
	{
		getCore()->getResources()->load<AudioSource>(path)->play();
	}

	

}