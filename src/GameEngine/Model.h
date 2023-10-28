#pragma once
#include <memory>
#include "Resource.h"

namespace myengine
{
	struct Texture;
	struct Model : Resource
	{
		void onLoad() override;
		void linkTexture(std::shared_ptr<Texture> tex);
	private:
		std::shared_ptr<graphics::Model> m_model;
		std::weak_ptr<Texture> m_texture;
	};
}