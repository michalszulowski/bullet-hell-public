#ifndef PROJ_2_BULLET_HELL_GAME_H
#define PROJ_2_BULLET_HELL_GAME_H

#include "ImageRenderer.h"
#include "sptr.h"
#include "BmpResourceManager.h"
#include "GameMenu.h"

class Game {
private:
    sptr<ImageRenderer> imageRenderer;
    sptr<BmpResourceManager> resourceManager;
    sptr<GameMenu> menu;
    SDL_Surface* charset;
    LevelResult lastLevelResult = G_EXIT;


public:
    Game();
    ~Game();
    void start();

private:
    void startMainLoop();
    sptr<CharSeq> getInfoDependingOn(LevelResult result);
    void handleChosenLevel();
};


#endif //PROJ_2_BULLET_HELL_GAME_H
