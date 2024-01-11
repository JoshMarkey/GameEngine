#include "PointLight.h"
#include "Core.h"
namespace myengine
{
	void myengine::PointLight::onInitialise()
	{
		m_brightness = 1;
		std::shared_ptr<PointLight> self = getEntity()->getComponent<PointLight>();
		getCore()->m_lights.push_back(self);

	}

	float myengine::PointLight::getBrightness()
	{
		return m_brightness;
	}

	void myengine::PointLight::setBrightness(float _brightness)
	{
		if (_brightness >= 0 && _brightness <= 1)
			m_brightness = _brightness;
	}
}
