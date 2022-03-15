#ifndef PROJ_2_BULLET_HELL_IMAGERENDERER_H
#define PROJ_2_BULLET_HELL_IMAGERENDERER_H

#include "sdlinclude.h"

class ImageRenderer {
private:
    SDL_Surface* image;
    SDL_Texture *texture;
    SDL_Window *window;
    SDL_Renderer *renderer;
    int windowWidth;
    int windowHeight;
    const char* windowTitle;
    bool initialized;

public:
    ImageRenderer(int windowWidth, int windowHeight, const char* windowTitle);
    ~ImageRenderer();

    void renderImage();
    void openWindow();
    SDL_Surface* getImage();
    void destroyResources();
};


#endif //PROJ_2_BULLET_HELL_IMAGERENDERER_H
