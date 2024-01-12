#include "Menu.h"
#include "GameManager.h"

void Menu::init(std::shared_ptr<GameManager> _gm)
{
	gameManager = _gm;
	playDefault = "../resources/Gui/PlayDefault.png";
	playPressed = "../resources/Gui/PlayHover.png";
	quitDefault = "../resources/Gui/QuitDefault.png";
	quitPressed = "../resources/Gui/QuitHover.png";

	playCurrent = playDefault;
	quitCurrent = quitDefault;
}

void Menu::onGui()
{
	int playResult = getGui()->button(myengine::Rect(300, 450, 400, 300), playCurrent);
	int quitResult = getGui()->button(myengine::Rect(300, 100, 400, 300), quitCurrent);

	switch (playResult)
	{
	case 0:
		playCurrent = playDefault;
		break;
	case 1:
		playCurrent = playPressed;
		break;
	case 2:
		gameManager->play();
		break;
	}

	switch (quitResult)
	{
	case 0:
		quitCurrent = quitDefault;
		break;
	case 1:
		quitCurrent = quitPressed;
		break;
	case 2:
		getCore()->m_running = false;
		break;
	}
}
