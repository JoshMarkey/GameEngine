#include "Component.h"
#include <glm/glm.hpp>

namespace myengine
{
	struct Transform : Component
	{
		Transform();
	public:
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
		glm::mat4 getProjection();
		glm::mat4 getModel();
		void rotate(glm::vec3 rot);
		
	};
}