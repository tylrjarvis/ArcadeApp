#include "InputController.h"
#include <SDL3/SDL.h>
#include "GameController.h"

InputController::InputController():mQuit(nullptr), mnoptrCurrentController(nullptr)
{

}

void InputController::Init(InputAction quitAction)
{
    mQuit = quitAction;
}

void InputController::Update(uint64_t dt)
{
    SDL_Event sdlEvent;

    while(SDL_PollEvent(&sdlEvent))
    {
        switch(sdlEvent.type)
        {
            case SDL_EVENT_QUIT:
                mQuit(dt, 0);
                break;
            case SDL_EVENT_MOUSE_MOTION:
                if(mnoptrCurrentController)
                {
                    if(MouseMovedAction mouseMoved = mnoptrCurrentController->GetMouseMovedAction())
                    {
                        MousePosition position;
                        position.xPos = sdlEvent.motion.x;
                        position.yPos = sdlEvent.motion.y;
                        mouseMoved(position);
                    }
                }
                break;
            case SDL_EVENT_MOUSE_BUTTON_UP:
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                if(mnoptrCurrentController)
                {
                    MouseInputAction action = mnoptrCurrentController->GetMouseButtonActionForMouseButton(static_cast<MouseButton>(sdlEvent.button.button));

                    MousePosition position;
                    position.xPos = sdlEvent.button.x;
                    position.yPos = sdlEvent.button.y;

                    action(static_cast<InputState>(sdlEvent.button.type), position);
                }
                break;
            case SDL_EVENT_KEY_DOWN:
            case SDL_EVENT_KEY_UP:
                if(mnoptrCurrentController)
                {
                    InputAction action = mnoptrCurrentController->GetActionForKey(sdlEvent.key.key);

                    action(dt, static_cast<InputState>(sdlEvent.key.type));
                }
                break;
        }
    }
}

void InputController::SetGameController(GameController* controller)
{
    mnoptrCurrentController = controller;
}