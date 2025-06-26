#include "GameController.h"
#include <SDL3/SDL.h>
#define BUTTON_RELEASED 0
#define BUTTON_PRESSED 1

GameController::GameController()
{

}

InputAction GameController::GetActionForKey(InputKey key)
{
    for(const auto& buttonAction: mButtonActions)
    {
        if(key == buttonAction.key)
        {
            return buttonAction.action;
        }
    }

    return [](uint32_t, InputState){};
}

void GameController::AddInputActionForKey(const ButtonAction& buttonAction)
{
    mButtonActions.push_back(buttonAction);
}

void GameController::ClearAll()
{
    mButtonActions.clear();
}

bool GameController::IsPressed(InputState state)
{
    return state == BUTTON_PRESSED;
}

bool GameController::IsReleased(InputState state)
{
    return state == BUTTON_RELEASED;
}

InputKey GameController::ActionKey()
{
    return static_cast<InputKey>(SDLK_A);
}

InputKey GameController::CancelKey()
{
    return static_cast<InputKey>(SDLK_S);
}

InputKey GameController::LeftKey()
{
    return static_cast<InputKey>(SDLK_LEFT);
}

InputKey GameController::RightKey()
{
    return static_cast<InputKey>(SDLK_RIGHT);
}

InputKey GameController::UpKey()
{
    return static_cast<InputKey>(SDLK_UP);
}

InputKey GameController::DownKey()
{
    return static_cast<InputKey>(SDLK_DOWN);
}