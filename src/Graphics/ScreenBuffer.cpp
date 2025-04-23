#include "ScreenBuffer.h"
#include <SDL3/SDL.h>
#include <assert.h>

// Default constructor initializing mSurface to nullptr
ScreenBuffer::ScreenBuffer(): mSurface(nullptr)
{
    
}

// Copy constructor that creates a new surface by copying from another ScreenBuffer
ScreenBuffer::ScreenBuffer(const ScreenBuffer& screenBuffer)
{
    mSurface = SDL_CreateSurface(screenBuffer.mSurface->w, screenBuffer.mSurface->h, screenBuffer.mSurface->format);
    SDL_BlitSurface(screenBuffer.mSurface, nullptr, mSurface, nullptr);
}

// Destructor that cleans up the surface if it exists
ScreenBuffer::~ScreenBuffer()
{
    if(mSurface)
    {
        SDL_DestroySurface(mSurface);
    }
}

// Assignment operator that handles self-assignment and copies surface data
ScreenBuffer& ScreenBuffer::operator=(const ScreenBuffer& screenBuffer)
{
    if(this == &screenBuffer)
    {
        return *this;
    }
    if(mSurface != nullptr)
    {
        SDL_DestroySurface(mSurface);
        mSurface = nullptr;
    }
    if(screenBuffer.mSurface != nullptr)
    {
        mSurface = SDL_CreateSurface(screenBuffer.mSurface->w, screenBuffer.mSurface->h, screenBuffer.mSurface->format);
        SDL_BlitSurface(screenBuffer.mSurface, nullptr, mSurface, nullptr);
    }
    return *this;
}

// Initializes the surface with specified format, width, and height
void ScreenBuffer::Init(const SDL_PixelFormatDetails* formatDetails, uint32_t width, uint32_t height)
{
    mSurface = SDL_CreateSurface(width, height, formatDetails->format);
    Clear();
}

// Clears the surface with a specified color
void ScreenBuffer::Clear(const Color& color)
{
    assert(mSurface);
    if(mSurface)
    {
        SDL_FillSurfaceRect(mSurface, nullptr, color.GetPixelColor());  
    }
}

// Sets a pixel at coordinates (x,y) to the specified color
void ScreenBuffer::SetPixel(const Color& color, int x, int y)
{
    assert(mSurface);
    if((mSurface) && 
       (y < mSurface->h) && 
       (y >= 0) && 
       (x < mSurface->w) && 
       (x >= 0))
    {
        SDL_LockSurface(mSurface);
        uint32_t* pixels = (uint32_t*)mSurface->pixels;
        uint32_t index = GetPixelIndex(y, x);
        pixels[index] = color.GetPixelColor();
        SDL_UnlockSurface(mSurface);
    }
}

// Calculates the pixel index in the surface's pixel array for given row and column
uint32_t ScreenBuffer::GetPixelIndex(int row, int column)
{   
    assert(mSurface);
    if(mSurface)
    {
        return static_cast<size_t>(row) * static_cast<size_t>(mSurface->w) + static_cast<size_t>(column);
    }
    return 0;
}
