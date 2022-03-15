#include "Animation.h"

Animation::Animation(sptr<ArrayList<SDL_Surface *>> sprites, long changeSpriteFor) {
    this->sprites = sprites;
    this->changeSpriteFor = changeSpriteFor;
    numberOfSprites = sprites->getSize();
    if (numberOfSprites == 0) {
        throw IllegalArgumentException("Empty list given to Animation");
    }
}

SDL_Surface *Animation::getImage(long time) {
    int spriteIndex = (time / changeSpriteFor) % numberOfSprites;
    return sprites->get(spriteIndex);
}