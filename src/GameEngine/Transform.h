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
		glm::mat4 getProjection();
		glm::mat4 getModel();
		void rotate(float angle, glm::vec3 rot);
		glm::mat4 rotmat;
		
	};
}