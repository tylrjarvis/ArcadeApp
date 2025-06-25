#ifndef APP_APP_H
#define APP_APP_H

#include "Screen.h"
#include <stdint.h>
#include <vector>
#include <memory>
#include "Scene.h"

struct SDL_Window;

class App
{
    public:
        static App& Singleton();
        bool Init(uint32_t width, uint32_t height, uint32_t mag);
        void Run();

        inline uint32_t GetWidth() const {return mScreen.GetWidth();}
        inline uint32_t GetHeight() const {return mScreen.GetHeight();}

        void PushScene(std::unique_ptr<Scene> scene);
        void PopScene();
        Scene* TopScene();

    private:
        Screen mScreen;
        SDL_Window* mnoptrWindow;
        std::vector<std::unique_ptr<Scene>> mSceneStack;
        App() {};
        App(const App&) = delete;
        App& operator=(const App&) = delete;
};

#endif /* APP_APP_H */