#pragma once
#include "Collider.h"

namespace myengine
{
	struct BoxCollider : Collider
	{
		/*
		Box collider shape for use in Pellet libary.
		This needs to be made before the rigid body.
		*/
	public:
		void onInitialise() override;
	
	private:

	};
}