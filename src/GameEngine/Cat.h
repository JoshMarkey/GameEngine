#include "Component.h"
#include <Graphics/rend.h>

namespace myengine
{
	struct Cat : Component
	{
		Cat();
		~Cat();
	public:
		void onTick() override;
		void onInitialise() override;
		float angle;
	private:
		graphics::Camera m_cam;
		std::string modelPath;
		std::string texPath;
		std::string vertPath;
		std::string fragPath;
	};
}