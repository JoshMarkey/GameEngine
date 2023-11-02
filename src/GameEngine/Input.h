#include <SDL2/SDL.h>
namespace myengine
{
	struct Core;
	struct Input
	{
        void handleKeyboardEvent(SDL_Event Event) {
            keyState[Event.code] = event.state;
        }

        bool isPressed(keyCode) {
            return (keyState[keyCode] == PRESSED);
        }

        bool isReleased(keyCode) {
            return (keyState[keyCode] == RELEASED);
        }

        keyState[];
    }


        while (SDL Pull events)
        {
            switch (event.type) {
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                keyHandler.handleKeyboardEvent(event);
                break;
            case SDL_ANOTHER_EVENT:
                ...
                    break;
            }
        }

	};
}