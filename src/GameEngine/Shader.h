#pragma once
#include <memory>
#include "Resource.h"

namespace myengine
{
	/*
	Shader resource contains shader program.
	This includes both vertex and fragment shaders
	*/
	struct Shader : Resource
	{
	public:
		void onLoad(std::string _path) override;
		std::shared_ptr<graphics::Shader> m_shader;//Wrapped openGL Shader program
		
	};
}