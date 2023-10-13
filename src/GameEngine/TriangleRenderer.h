#include "Component.h"
#include <Graphics/rend.h>

namespace myengine
{
	struct TriangleRenderer : Component
	{
		TriangleRenderer();
		~TriangleRenderer();

	private:
		Vao m_Quad;
		void onDisplay();
		Model m_mesh;
		Shader m_shader;
		Camera m_cam;
		Texture m_tex;
	};
}