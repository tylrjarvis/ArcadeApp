
#ifndef SCREENBUFFER_H
#define SCREENBUFFER_H

#include <stdint.h>
#include "Color.h"

struct SDL_Surface;

class ScreenBuffer
{    
    private:
        SDL_Surface* mSurface;
        uint32_t GetPixelIndex(int row, int column);

    public:
        ScreenBuffer();
        ScreenBuffer(const ScreenBuffer& screenBuffer);
        ~ScreenBuffer();

        ScreenBuffer& operator=(const ScreenBuffer& screenBuffer);

        void Init(const SDL_PixelFormatDetails* formatDetails, uint32_t width, uint32_t height);

        inline SDL_Surface* GetSurface() const {return mSurface;}

        void Clear(const Color& color = Color::Black());
        void SetPixel(const Color& color, int x, int y);
};

#endif