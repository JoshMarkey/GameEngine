#include "Model.h"

namespace myengine
{
	void Model::onLoad()
	{
		model = std::make_shared<graphics::Model>(getPath().c_str());
	}
}
