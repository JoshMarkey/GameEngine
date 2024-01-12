#pragma once
#include <memory>
#include <Graphics/Vao.h>
#include <Graphics/Vbo.h>
#include "Utility.h"
#include <string>

namespace myengine
{
	struct Core;
	struct Shader;
	/*
	This acts as an ortho camera as well as an interface to draw ortho objects
	Shortcuts for drawing an image and button
	*/
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
		void image(myengine::Rect _rect, std::string _texPath);//Draws a rect with texture
		int button(myengine::Rect _rect, std::string _texPath);//Return 0 for no interaction, 1 for hover, 2 for click

	private:
		void draw(myengine::Rect _rect, std::string _texPath);
		//Convert an input pixel coord to normalized device coords
		float convertCoords(float _inputPixel, float _winStart, float _winEnd, float _rangeLow, float _rangeHigh); //Convert pixel coords to screen space coord system - Easy for user to specify pixel positions
		
	};
}