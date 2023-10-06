#include "Component.h"
namespace myengine
{
	void Component::tick()
	{
		onTick();
	}
}