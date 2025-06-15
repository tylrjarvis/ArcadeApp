#include <iostream>
#include <SDL3/SDL.h>
#include "Color.h"
#include "Screen.h"
#include "Line2D.h"
#include "Triangle.h"
// Constants
const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3;

int main(int argc, char* argv[])
{
    Screen screen;
    screen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
    Line2D line = {Vec2D(0, 0), Vec2D(SCREEN_WIDTH, SCREEN_HEIGHT)};
    Triangle triangle = {Vec2D(60, 10), Vec2D(10, 110), Vec2D(110, 110)};

    screen.Draw(triangle, Color::Red());
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