#pragma once
#include "Component.h"

namespace myengine
{
	//Simple point light component.
	//Place in world to create a light source
	//Only the first light is currently supported. See ModelRenderer.
	struct PointLight : Component
	{
		void onInitialise() override;
		float getBrightness();
		void setBrightness(float _brightness);//Change brightness of light(0-1)
	private:
		float m_brightness;
	};
}