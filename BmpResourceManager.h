#ifndef PROJ_2_BULLET_HELL_BMPRESOURCEMANAGER_H
#define PROJ_2_BULLET_HELL_BMPRESOURCEMANAGER_H

#include "sdlinclude.h"
#include "CharSeqKeyDictionary.h"

class BmpResourceManager {
private:
    sptr<CharSeqKeyDictionary<SDL_Surface*>> resourceDict;

public:
    BmpResourceManager();
    //Loads resource if not loaded yet and returns it
    SDL_Surface* getResource(sptr<CharSeq> path);
    void freeResources();

private:
    SDL_Surface* loadSurface(sptr<CharSeq> path);
};


#endif //PROJ_2_BULLET_HELL_BMPRESOURCEMANAGER_H
