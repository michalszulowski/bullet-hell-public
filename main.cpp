#include "MathAndCalc.h"
#include "sptr.h"
#include "ImageRenderer.h"
#include "BmpResourceManager.h"
#include "GameCamera.h"
#include "SdlUtils.h"
#include "GameMenu.h"

sptr<CharSeq> getInfoDependingOn(LevelResult result) {
    if (result == PLAYER_WON) {
        return new CharSeq("Gratulacje, wygrales, sprobuj nowy poziom");
    } else if (result == ENEMY_WON) {
        return new CharSeq("Niestety przegrales, sprobuj jeszcze raz");
    }
    return new CharSeq("witamy w grze");
};

void mainLoop() {
    sptr<ImageRenderer> renderer = new ImageRenderer(1000, 600, "Testowy poziom");
    renderer->openWindow();
    sptr<BmpResourceManager> resourceManager = new BmpResourceManager();
    SDL_Surface* charset = resourceManager->getResource(new CharSeq("./files/util/charset.bmp"));
    sptr<GameMenu> menu;
    LevelResult result = G_EXIT;
    menu = new GameMenu(renderer, resourceManager, charset);
    while (!menu->getExit()) {
        menu = new GameMenu(renderer, resourceManager, charset);
        menu->setInfo(getInfoDependingOn(result));
        menu->startMainLoop();
        if (menu->getExit()) {
            break;
        }
        sptr<GameLevel> level = menu->getChosenLevel();
        level->initialize();
        level->startMainLoop();
        result = level->getResult();
    }
    resourceManager->freeResources();
    renderer->destroyResources();
}

int runNewMain(int changeImageFor) {
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL_Init error: %s\n", SDL_GetError());
        return 1;
    }
    mainLoop();
    printf("quitting SDL\n");
    SDL_Quit();
    return 0;
}

int main(int argc, char **argv) {
    runNewMain(0);
    return 0;
};
