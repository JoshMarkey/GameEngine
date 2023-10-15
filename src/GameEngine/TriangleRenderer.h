#include "Component.h"
#include <Graphics/rend.h>

namespace myengine
{
	struct TriangleRenderer : Component
	{
		TriangleRenderer();
		~TriangleRenderer();
	public:
		void onDisplay() override;
		void initialize();
	private:
		Vao m_Quad;
		Model m_mesh;
		Shader m_shader;
		Camera m_cam;
		Texture m_tex;
	};
}