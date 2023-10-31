#pragma once
#include <memory>
#include "Resource.h"

namespace myengine
{
	struct Shader : Resource
	{
	public:
		void onLoad(std::string _path) override;
		std::shared_ptr<graphics::Shader> m_shader;
		
	private:
	};
}