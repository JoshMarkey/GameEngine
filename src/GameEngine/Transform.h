#include "Component.h"
#include <glm/glm.hpp>

namespace myengine
{
	struct Transform : Component
	{
	public:
		glm::vec3 position;
		glm::vec3 rotation;
		
	};
}