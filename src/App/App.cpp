#include "App.h"
#include "ArcadeScene.h"
#include <SDL3/SDL.h>
#include <iostream> 
#include <cassert>
#include "InputController.h"
App& App::Singleton()
{
    static App theApp;
    return theApp;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t mag)
{
    mnoptrWindow = mScreen.Init(width, height, mag);

    std::unique_ptr<ArcadeScene> arcadeScene = std::make_unique<ArcadeScene>();
    PushScene(std::move(arcadeScene));

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

        //Input
        mInputController.Init([&running](uint32_t dt, InputState state)
        {
            running = false;
        });

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

            mInputController.Update(dt);

            Scene* topScene = App::TopScene();
            assert(topScene && "Ensure that a scene exists");
            if(topScene)
            {
                //Update
                while(accumulator >= dt)
                {
                    topScene->Update(dt);
                    accumulator -= dt;
                }

                //Render
                topScene->Draw(mScreen);
            }

            mScreen.SwapScreens();
        }
    }
}

void App::PushScene(std::unique_ptr<Scene> scene)
{
    assert(scene && "Don't push a nullptr to the scene stack");
    if(scene)
    {
        scene->Init();
        mInputController.SetGameController(scene->GetGameController());
        mSceneStack.emplace_back(std::move(scene));
        SDL_SetWindowTitle(mnoptrWindow, TopScene()->GetSceneName().c_str());
    }
}

void App::PopScene()
{
    if(mSceneStack.size() > 1)
    {
        mSceneStack.pop_back();
    }

    if(TopScene())
    {
        mInputController.SetGameController(TopScene()->GetGameController());
        SDL_SetWindowTitle(mnoptrWindow, TopScene()->GetSceneName().c_str());
    }
}

Scene* App::TopScene()
{
    if(mSceneStack.empty())
    {
        return nullptr;
    }
    
    return mSceneStack.back().get();
}