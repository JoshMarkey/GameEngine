#include "Texture.h"
namespace myengine
{
	void myengine::Texture::onLoad(std::string _path)
	{
		path = _path;
		m_texture = std::make_shared<graphics::Texture>();
		m_texture->load(getPath().c_str());
	}
	std::shared_ptr<graphics::Texture> Texture::getTexture()
	{
		return m_texture;
	}
}
