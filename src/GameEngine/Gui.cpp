#include "Gui.h"
#include "Core.h"
namespace myengine
{
	void Gui::initialise(std::shared_ptr<Core> _core)
	{
		m_core = _core;

		std::shared_ptr<graphics::Vbo> pos = std::make_shared<graphics::Vbo>();
		pos->add(glm::vec3(0.0f, 1.0f, 0.0f));
		pos->add(glm::vec3(0.0f, 0.0f, 0.0f));
		pos->add(glm::vec3(1.0f, 0.0f, 0.0f));
		pos->add(glm::vec3(1.0f, 0.0f, 0.0f));
		pos->add(glm::vec3(1.0f, 1.0f, 0.0f));
		pos->add(glm::vec3(0.0f, 1.0f, 0.0f));


		std::shared_ptr<graphics::Vbo> coords = std::make_shared<graphics::Vbo>();
		coords->add(glm::vec2(0.0f, 0.0f));
		coords->add(glm::vec2(0.0f, 1.0f));
		coords->add(glm::vec2(1.0f, 1.0f));
		coords->add(glm::vec2(1.0f, 1.0f));
		coords->add(glm::vec2(1.0f, 0.0f));
		coords->add(glm::vec2(0.0f, 0.0f));

		m_Quad.addVbo(pos);
		m_Quad.addVbo(coords);

		m_fragPath = "../resources/Shaders/GUI/FragShader.txt";
		m_vertPath = "../resources/Shaders/GUI/VertShader.txt";
	}

	std::shared_ptr<Shader> Gui::getShader()
	{
		return m_core->getResources()->load<Shader>(m_fragPath, m_vertPath);
	}

	glm::mat4 Gui::getProjection()
	{
		return glm::ortho(0.0f,1000.0f,0.0f,800.0f, -1.0f, 1.0f);
	}
	void Gui::image(myengine::Rect _rect, std::string _texPath)
	{
		draw(_rect, _texPath);
	}
	int Gui::button(myengine::Rect rect, std::string texPath)
	{
		image(rect, texPath);

		glm::vec2 winSize = m_core->getWindowSize();
		glm::vec2 mousePos = m_core->getInput()->m_mousePos;

		if (mousePos.x >= rect.x && mousePos.x <= rect.x + rect.w && winSize.y - mousePos.y >= rect.y && winSize.y - mousePos.y <= rect.y + rect.h)
		{
			if (m_core->getInput()->getKeyUp(KeyCodes::leftMouse))
			{
				return 2;
			}
			else
			{
				return 1;
			}
		}

		return 0;
	}

	void Gui::draw(myengine::Rect _rect, std::string _texPath)
	{
		std::shared_ptr<Texture> tex = m_core->getResources()->load<Texture>(_texPath);
		std::shared_ptr<Shader> guiShader = getShader();

		glm::mat4 model = glm::mat4(1);
		glm::vec3 pos{ -1 };
		glm::vec2 winSize = m_core->getWindowSize();
		pos.x = convertCoords(_rect.x,0,winSize.x, 0, 1);
		pos.y = convertCoords(_rect.y, 0, winSize.y, 0, 1);

		model = glm::translate(model, glm::vec3(_rect.x, _rect.y, -1));
		model = glm::scale(model, glm::vec3(_rect.w, _rect.h, 1));

		guiShader->m_shader->bindOrthoMatrix(getProjection(), model);
		guiShader->m_shader->renderOrtho(&m_Quad, tex->getTexture().get());
	}
	
	float Gui::convertCoords(float inputPixel, float winStart, float winEnd, float rangeLow, float rangeHigh)
	{
		return(inputPixel - winStart) * ((rangeHigh - rangeLow) / (winEnd - winStart)) + rangeLow;
	}
}