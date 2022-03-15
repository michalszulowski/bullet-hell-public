#ifndef PROJ_2_BULLET_HELL_GAMEMENU_H
#define PROJ_2_BULLET_HELL_GAMEMENU_H

#include "ArrayList.h"
#include "GameLevel.h"

class GameMenu {
    sptr<List<sptr<GameLevel>>> availableLevels;
    sptr<GameLevel> chosenLevel;
    sptr<ImageRenderer> imageRenderer;
    sptr<BmpResourceManager> resourceManager;
    SDL_Surface* charset;
    SDL_Surface *backgroundImg;
    bool exit = false;
    sptr<CharSeq> info;
    bool running;

public:
    GameMenu(sptr<ImageRenderer> imageRenderer, sptr<BmpResourceManager> resourceManager, SDL_Surface* charset);
    bool startMainLoop();
    sptr<GameLevel> getChosenLevel();
    void setInfo(sptr<CharSeq> info);
    bool getExit();

private:
    void showAvailableLevels();
    void performMainLoop();
    void handleEvent(SDL_Event event);
    void handleKeyDown(SDL_Keycode key);
};

#endif //PROJ_2_BULLET_HELL_GAMEMENU_H
