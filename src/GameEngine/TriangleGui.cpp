#include "TriangleGui.h"
#include "Core.h"
#include "Texture.h"
#include "Gui.h"

namespace myengine
{
	void TriangleGui::onInitialise()
	{
		pressed = false;
	}
	void TriangleGui::onGui()
	{
		getGui()->image(myengine::Rect(400, 300, 200, 200), "../Models/OtherTextures/Image.png");
		if (pressed)
		{
			if (getGui()->button(myengine::Rect(200, 50, 200, 200), "../Models/OtherTextures/button1.png"))
			{
				pressed = false;
			}
		}
		else if(getGui()->button(myengine::Rect(200, 50, 200, 200), "../Models/OtherTextures/button2.png"))
		{
			pressed = true;
		}

	}
}