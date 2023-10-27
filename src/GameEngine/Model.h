#pragma once
#include <memory>
#include "Resource.h"

namespace myengine
{

	struct Model : Resource
	{
		void onLoad();
	private:
		std::shared_ptr<graphics::Model> model;
	};
}