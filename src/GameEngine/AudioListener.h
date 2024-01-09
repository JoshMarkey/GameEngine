#pragma once
#include "Component.h"
#include "glm/vec3.hpp"

namespace myengine
{
	struct AudioListener : Component
	{
	public:
		glm::vec3 lastPos{0};
		void onTick() override;
	private:

	};
}