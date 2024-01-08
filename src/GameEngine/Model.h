#pragma once
#include <memory>
#include "Resource.h"

namespace myengine
{
	struct Texture;
	struct Model : Resource
	{
		void onLoad(std::string _path) override;
		void linkTexture(std::shared_ptr<Texture> tex);
		void render();
		std::shared_ptr<graphics::Model> getModel();
		std::shared_ptr<graphics::Texture> getTexture();
		std::vector<bu::Face> getFaces();
	private:
		std::shared_ptr<graphics::Model> m_model;
		std::weak_ptr<Texture> m_texture;
	};
}