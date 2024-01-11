#pragma once
#include "Component.h"

namespace myengine
{
	struct PointLight : Component
	{
		void onInitialise() override;
		float getBrightness();
		void setBrightness(float _brightness);
	private:
		float m_brightness;
	};
}