#pragma
#include <memory>
#include <Graphics/Vao.h>
#include <Graphics/Vbo.h>
#include "Utility.h"
#include <string>

namespace myengine
{
	struct Core;
	struct Shader;

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
		void image(myengine::Rect rect, std::string texPath);
		bool button(myengine::Rect rect, std::string texPath);

	private:
		void draw(myengine::Rect _rect, std::string _texPath);
		//Convert an input pixel coord to normalized device coords
		float convertCoords(float inputPixel, float winStart, float winEnd, float rangeLow, float rangeHigh);
		
	};
}