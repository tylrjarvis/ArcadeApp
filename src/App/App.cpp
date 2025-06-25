#include "App.h"
#include <SDL3/SDL.h>
#include <iostream> 
#include "ArcadeScene.h"
#include <memory>

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
        // Main loop setup
        SDL_Event event;
        bool running = true;
        
        uint64_t lastTick = SDL_GetTicks();
        uint64_t currentTick = lastTick;
        uint64_t dt = 10;
        uint64_t accumulator = 0;

        std::unique_ptr<ArcadeScene> arcadeScene = std::make_unique<ArcadeScene>();
        arcadeScene->Init();

        // Main loop
        while (running)
        {
            currentTick = SDL_GetTicks();
            uint64_t frameTime = currentTick - lastTick;

            if(frameTime > 300)
            {
                frameTime = 300;
            }

            lastTick = currentTick;

            accumulator += frameTime;

            //Input
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

            //Update
            while(accumulator >= dt)
            {
                arcadeScene->Update(dt);
                accumulator -= dt;
            }

            //Render
            arcadeScene->Draw(mScreen);
            mScreen.SwapScreens();
        }
    }
}