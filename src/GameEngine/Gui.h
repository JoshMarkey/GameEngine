#include <memory>
#include <Graphics/Vao.h>
#include <Graphics/Vbo.h>
namespace myengine
{
	struct Core;
	struct Shader;

	//Simple rect to keep track of gui component positions and size
	struct Rect;

	struct Gui
	{
		void initialise(std::shared_ptr<Core> _core);
		
		graphics::Vao m_Quad;
		std::shared_ptr<Shader> getShader();
		std::string fragPath;
		std::string vertPath;
		std::shared_ptr<Core> m_core;
		glm::mat4 getProjection();
	public:
		void image(rect )
		
	};
}