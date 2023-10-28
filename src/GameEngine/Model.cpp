#include "Model.h"

namespace myengine
{
	void Model::onLoad()
	{
		m_model = std::make_shared<graphics::Model>(getPath().c_str());
	}
	void Model::linkTexture(std::shared_ptr<Texture> tex)
	{
		m_texture = tex;
	}
}
