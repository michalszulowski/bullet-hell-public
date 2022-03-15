#include "BmpResourceManager.h"
#include <stdio.h>

BmpResourceManager::BmpResourceManager() {
    resourceDict = new CharSeqKeyDictionary<SDL_Surface*>();
}

SDL_Surface *BmpResourceManager::getResource(sptr<CharSeq> path) {
    SDL_Surface* result;
    try {
        result = resourceDict->get(path);
    } catch (const NoSuchElementException&) {
        result = loadSurface(path);
    }
    return result;
}

void BmpResourceManager::freeResources() {
    for (int i = 0; i < resourceDict->getPairList()->getSize(); ++i) {
        char* name = resourceDict->getPairList()->get(i).key->asArray();
        printf("Freeing %s\n", name);
        SDL_Surface* resource = resourceDict->getPairList()->get(i).value;
        SDL_FreeSurface(resource);
        printf("Freed %s\n", name);
    }
}

SDL_Surface* BmpResourceManager::loadSurface(sptr<CharSeq> path) {
    char* arr = path->asArray();
    SDL_Surface* surface = SDL_LoadBMP(arr);
    delete[] arr;
    if (surface == NULL) {
        throw ResourceNotLoadedException();
    }
    resourceDict->put(path, surface);
    return surface;
}
