#ifndef PROJ_2_BULLET_HELL_SDLUTILS_H
#define PROJ_2_BULLET_HELL_SDLUTILS_H

#include "sdlinclude.h"

class SdlUtils {
public:
    static void drawString(SDL_Surface *screen, int x, int y, const char *text, SDL_Surface *charset);
    static void drawSurface(SDL_Surface *screen, SDL_Surface *sprite, int x, int y);
    static void drawPixel(SDL_Surface *surface, int x, int y, Uint32 color);
    static void drawLine(SDL_Surface *screen, int x, int y, int l, int dx, int dy, Uint32 color);
    static void drawRectangle(SDL_Surface *screen, int x, int y, int l, int k, Uint32 outlineColor, Uint32 fillColor);
    static void drawPartiallyFilledRectangle(SDL_Surface *screen, double fulfillmentFactor, int x, int y, int l, int k,
                                             Uint32 outlineColor, Uint32 fillColor, Uint32 backColor);
};


#endif //PROJ_2_BULLET_HELL_SDLUTILS_H
