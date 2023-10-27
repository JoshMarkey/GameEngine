#include "Texture.h"
namespace myengine
{
	void myengine::Texture::onLoad()
	{
		tex.load(getPath().c_str());
	}
}
