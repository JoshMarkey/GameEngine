#pragma once
#include <memory>
#include "Resource.h"

namespace myengine 
{
	struct Texture : private Resource
	{
	public:
		void onLoad() override;

		std::shared_ptr<graphics::Texture> m_texture;
	private:
	};
}