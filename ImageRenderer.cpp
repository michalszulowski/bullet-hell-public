#include "ImageRenderer.h"
#include <iostream>
#include "exceptions.h"

ImageRenderer::ImageRenderer(int windowWidth, int windowHeight, const char* windowTitle) {
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
    this->windowTitle = windowTitle;
    image = SDL_CreateRGBSurface(0, windowWidth, windowHeight, 32,
                                 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
}

ImageRenderer::~ImageRenderer() {
}

void ImageRenderer::destroyResources() {
    SDL_FreeSurface(image);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void ImageRenderer::openWindow() {
    int failed = SDL_CreateWindowAndRenderer(windowWidth, windowHeight, 0,
                                             &window, &renderer);
    if(failed != 0) {
        SDL_Quit();
        printf("SDL_CreateWindowAndRenderer error: %s\n", SDL_GetError());
    };

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, windowWidth, windowHeight);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_SetWindowTitle(window, windowTitle);

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                                   SDL_TEXTUREACCESS_STREAMING,
                                   windowWidth, windowHeight);
    initialized = true;
}

void ImageRenderer::renderImage() {
    if (!initialized) {
        throw ObjectNotInitializedException();
    }
    SDL_UpdateTexture(texture, NULL, image->pixels, image->pitch);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

SDL_Surface* ImageRenderer::getImage() {
    return image;
}
