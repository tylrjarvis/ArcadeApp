#ifndef COLOR_H
#define COLOR_H

#include <stdint.h>
#include <SDL3/SDL_pixels.h>

struct SDL_PixelFormatDetails;

class Color
{
    private:
        size_t mColor;

    public:
        static const SDL_PixelFormatDetails* mFormat;
        static void InitColorFormat(const SDL_PixelFormatDetails* formatDetails);

        static Color Black() {return Color(0, 0, 0, 255);}
        static Color White() {return Color(255, 255, 255, 255);}
        static Color Red() {return Color(255, 0, 0, 255);}
        static Color Green() {return Color(0, 255, 0, 255);}
        static Color Blue() {return Color(0, 0, 255, 255);}
        static Color Yellow() {return Color(255, 255, 0, 255);}
        static Color Magenta() {return Color(255, 0, 255, 255);}
        static Color Cyan() {return Color(37, 240, 217, 255);}
        static Color Pink() {return Color(252, 197, 224, 255);}
        static Color Orange() {return Color(245, 190, 100, 255);}
        static Color Purple() {return Color(128, 0, 128, 255);}

        Color(): Color(0){}
        Color(uint32_t color): mColor(color){}
        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

        inline bool operator==(const Color& c) const {return mColor == c.mColor;}
        inline bool operator!=(const Color& c) const {return !(*this == c);}
        inline size_t GetPixelColor() const {return mColor;}

        void SetRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

        void SetRed(uint8_t red);
        void SetGreen(uint8_t green);
        void SetBlue(uint8_t blue);
        void SetAlpha(uint8_t alpha);

        uint8_t GetRed() const;
        uint8_t GetGreen() const;
        uint8_t GetBlue() const;
        uint8_t GetAlpha() const;
      
};

#endif
