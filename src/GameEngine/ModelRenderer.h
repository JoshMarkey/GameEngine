#pragma once
#include "Component.h"
#include <Graphics/rend.h>

namespace myengine
{
	struct Entity;
	struct ModelRenderer : Component
	{
		void onDisplay(std::shared_ptr<Entity> camera) override;
		void onInitialise() override;
		void setFrag(std::string p);
		void setVert(std::string p);
		void setModel(std::string p);
		void setTexture(std::string p);
	private:
		graphics::Camera m_cam;
		std::string modelPath;
		std::string texPath;
		std::string vertPath;
		std::string fragPath;
	};
}