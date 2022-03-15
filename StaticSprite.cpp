#include "StaticSprite.h"

StaticSprite::StaticSprite(SDL_Surface *image) {
    this->image = image;
}

SDL_Surface *StaticSprite::getImage(long time) {
    return image;
}
