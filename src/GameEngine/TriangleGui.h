#pragma once
#include "Component.h"
#include <Graphics/rend.h>

namespace myengine
{
	//Test component for GUI elements
	//Should only be used for testing
	struct TriangleGui : Component
	{
		void onInitialise() override;
		void onGui() override;
		bool pressed;
	};
}