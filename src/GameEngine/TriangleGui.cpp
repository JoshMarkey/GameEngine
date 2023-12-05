#include "TriangleGui.h"
#include "Core.h"
#include "Gui.h"
#include "Texture.h"

namespace myengine
{
	void TriangleGui::onGui()
	{
		std::shared_ptr<Texture> tex = getCore()->getResources()->load<Texture>("../Models/Cat/Tex.png");
		std::shared_ptr<Shader> guiShader = getCore()->getGui()->getShader();
		guiShader->m_shader->bindOrthoMatrix(getCore()->getGui()->getProjection(), glm::scale(glm::mat4(1),glm::vec3(100.0f)));
		guiShader->m_shader->renderOrtho(&getCore()->getGui()->m_Quad, tex->getTexture().get());

	}
}