#include "AnimationLoader.h"

AnimationLoader::AnimationLoader(sptr<BmpResourceManager> resourceManager) {
    this->resourceManager = resourceManager;
}

sptr<Displayable> AnimationLoader::loadOf(sptr<CharSeq> path1, sptr<CharSeq> path2, int changeFor) {
    sptr<ArrayList<SDL_Surface*>> sprites = new ArrayList<SDL_Surface*>(2);
    sprites->append(resourceManager->getResource(path1));
    sprites->append(resourceManager->getResource(path2));
    sptr<Displayable> animation = new Animation(sprites, changeFor);
    return animation;
}
