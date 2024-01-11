#pragma once
#include "Component.h"
#include <Graphics/rend.h>
#include "PointLight.h"

namespace myengine
{
	struct Entity;
	struct ModelRenderer : Component
	{
		void onDisplay() override;
		void onInitialise() override;
		void setFrag(std::string _p);
		void setVert(std::string _p);
		void setModel(std::string _p);
		void setTexture(std::string _p);
		std::vector<bu::Face> getFaces();
	private:
		graphics::Camera m_cam;
		std::string m_modelPath;
		std::string m_texPath;
		std::string m_lightVertPath;
		std::string m_lightFragPath;
		std::string m_defaultVertPath;
		std::string m_defaultFragPath;
	};
}