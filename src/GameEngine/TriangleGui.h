#pragma once
#include "Component.h"
#include <Graphics/rend.h>

namespace myengine
{
	struct TriangleGui : Component
	{
		void onInitialise() override;
		void onGui() override;
		bool pressed;
	};
}