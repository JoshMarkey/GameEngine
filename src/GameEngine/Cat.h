#pragma once
#include "Component.h"
#include <Graphics/rend.h>

namespace myengine
{
	struct Cat : Component
	{
		Cat();
		~Cat();
	public:
		void onTick() override;
		void onInitialise() override;
		float angle;
		bool player = false;
	private:
		graphics::Camera m_cam;
		std::string m_modelPath;
		std::string m_texPath;
		std::string m_vertPath;
		std::string m_fragPath;
	};
}
