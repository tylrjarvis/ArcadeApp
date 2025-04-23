#include <iostream>
#include <SDL3/SDL.h>
#include "Color.h"
#include "Screen.h"
#include "Line2D.h"
// Constants
const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3;

int main(int argc, char* argv[])
{
    Screen screen;
    screen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
    //screen.Draw((SCREEN_WIDTH-1)/2, (SCREEN_HEIGHT-1)/2, Color::Red());
    Line2D line = {Vec2D(0, 0), Vec2D(SCREEN_WIDTH, SCREEN_HEIGHT)};
    screen.Draw(line, Color::Red());
    screen.SwapScreens();

    // Main loop setup
    SDL_Event event;
    bool running = true;

    // Main loop
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                default:
                    break;
            }
        }
    }

    return 0;
}