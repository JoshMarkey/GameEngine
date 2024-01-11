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
		std::string m_fragPath;
		std::string m_vertPath;
		std::shared_ptr<Core> m_core;
		glm::mat4 getProjection();
	public:
		void image(myengine::Rect _rect, std::string _texPath);
		int button(myengine::Rect _rect, std::string _texPath);

	private:
		void draw(myengine::Rect _rect, std::string _texPath);
		//Convert an input pixel coord to normalized device coords
		float convertCoords(float _inputPixel, float _winStart, float _winEnd, float _rangeLow, float _rangeHigh);
		
	};
}