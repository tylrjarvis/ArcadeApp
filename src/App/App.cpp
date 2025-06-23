#include "App.h"
#include <SDL3/SDL.h>
#include "Color.h"
#include "Line2D.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

App& App::Singleton()
{
    static App theApp;
    return theApp;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t mag)
{
    mnoptrWindow = mScreen.Init(width, height, mag);
    return mnoptrWindow != nullptr;
}
void App::Run()
{
    if(mnoptrWindow)
    {
        Line2D line = {Vec2D(0, 0), Vec2D(mScreen.GetWidth(), mScreen.GetHeight())};
        Triangle triangle = {Vec2D(60, 10), Vec2D(10, 110), Vec2D(110, 110)};
        Rectangle rectangle = {Vec2D(mScreen.GetWidth()/2 - 25, mScreen.GetWidth()/2 - 25), 50, 50};
        Circle circle {Vec2D(mScreen.GetWidth()/2 + 50, mScreen.GetWidth()/2 + 50), 50};
        
        mScreen.Draw(triangle, Color::Red(), true, Color::Red());
        mScreen.Draw(rectangle, Color::Pink(), true, Color::Pink());
        //mScreen.Draw(circle, Color::Purple(), true, Color::Purple());
        mScreen.Draw(circle, Color(0, 255, 0, 150), true, Color(0, 255, 0, 150));
        mScreen.SwapScreens();
        
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
    }
}