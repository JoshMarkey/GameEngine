#include "Component.h"
namespace myengine
{
	void Component::onTick()
	{
	}
	void Component::onDisplay()
	{
	}
	void Component::initialize()
	{
	}
	void Component::tick()
	{
		onTick();
	}
}