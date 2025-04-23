#include "Screen.h"
#include "Vec2D.h"
#include "Line2D.h"
#include <SDL3/SDL.h>
#include <cassert>

Screen::Screen() : mWidth(0), mHeight(0), mWindow(nullptr), windowSurface(nullptr)
{
    
}

Screen::~Screen()
{
    if(mWindow)
    {
        SDL_DestroyWindow(mWindow);
        mWindow = nullptr;
    }
    
    SDL_Quit();
}

// Create window and surface
SDL_Window* Screen::Init(uint32_t width, uint32_t height, uint32_t mag)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != true)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    mWidth = width;
    mHeight = height;

    // Create window and surface
    mWindow = SDL_CreateWindow("Arcade", mWidth * mag, mHeight * mag, SDL_WINDOW_OPENGL);

    if(mWindow)
    {
        windowSurface = SDL_GetWindowSurface(mWindow);

        const SDL_PixelFormatDetails* pixelFormatDetails = SDL_GetPixelFormatDetails(windowSurface->format);

        Color::InitColorFormat(pixelFormatDetails);

        mClearColor = Color::Black();

        mBackBuffer.Init(pixelFormatDetails, width, height);

        mBackBuffer.Clear(mClearColor);

    }

    return mWindow;
}

void Screen::SwapScreens()
{
    assert(mWindow);
    if(mWindow)
    {
        ClearScreen();

        SDL_BlitSurface(mBackBuffer.GetSurface(), nullptr, windowSurface, nullptr);

        SDL_UpdateWindowSurface(mWindow);

        mBackBuffer.Clear(mClearColor);
    }
}

void Screen::ClearScreen()
{
    assert(mWindow);
    if(mWindow)
    {
        SDL_FillSurfaceRect(windowSurface, nullptr, mClearColor.GetPixelColor());
    }
}

void Screen::Draw(int x, int y, const Color& color)
{
    assert(mWindow);
    if(mWindow)
    {
        mBackBuffer.SetPixel(color, x, y);
    }
}

void Screen::Draw(const Vec2D& point, const Color& color)
{
    assert(mWindow);
    if(mWindow)
    {
        mBackBuffer.SetPixel(color, point.GetX(), point.GetY());
    }
}