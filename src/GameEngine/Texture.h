#pragma once
#include <memory>
#include "Resource.h"

namespace myengine 
{
	/*
	Texture loader
	*/
	struct Texture : Resource
	{
	public:
		void onLoad(std::string _path) override;
		std::shared_ptr<graphics::Texture> getTexture();
		std::shared_ptr<graphics::Texture> m_texture;
	private:
	};
}