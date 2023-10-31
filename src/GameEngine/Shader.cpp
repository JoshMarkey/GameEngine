#include "Shader.h"
namespace myengine
{
	void Shader::onLoad(std::string _path)
	{
		path = _path;
		m_shader = std::make_shared<graphics::Shader>(getPath().c_str(), secondPath);
	}
}