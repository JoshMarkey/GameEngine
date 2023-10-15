#include "Component.h"
namespace myengine
{
	void Component::onDisplay()
	{
	}
	void Component::tick()
	{
		onTick();
	}
}