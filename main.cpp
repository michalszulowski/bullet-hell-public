#include "sdlutil.h"
#include "MathAndCalc.h"
#include "sptr.h"
#include "ImageRenderer.h"
#include "Animation.h"
#include "BmpResourceManager.h"
#include "UnorderedList.h"
#include "Level1.h"
#include "StaticSprite.h"
#include "GameCamera.h"
#include "SdlUtils.h"
#include "Level3.h"
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
    sptr<ImageRenderer> renderer = sptr<ImageRenderer>(new ImageRenderer(1000, 600, "Testowy poziom"));
    renderer->openWindow();
    sptr<BmpResourceManager> resourceManager = new BmpResourceManager();
    SDL_Surface* charset = resourceManager->getResource(new CharSeq("./files/util/charset.bmp"));
    sptr<GameMenu> menu;
    LevelResult result = G_EXIT;
    menu = new GameMenu(renderer, resourceManager, charset);
    printf("Menu created \n");
    while (!menu->getExit()) {
        menu = new GameMenu(renderer, resourceManager, charset);
        printf("setting info \n");
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

int runTestLevel(int arg) {
    sptr<ImageRenderer> renderer = sptr<ImageRenderer>(new ImageRenderer(1000, 600, "Testowy poziom"));
    renderer->openWindow();
    sptr<BmpResourceManager> resourceManager = new BmpResourceManager();
    sptr<Displayable> background = new StaticSprite(resourceManager->getResource(new CharSeq("./files/backgrounds/chess.bmp")));

    sptr<GameLevel> level = new Level3(background, resourceManager, renderer);

    level->initialize();
    level->startMainLoop();

    printf("Freeing resources\n");
    resourceManager->freeResources();
    renderer->destroyResources();
    printf("Resources freed\n");

    return 0;
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

void unorderedListTests() {
    sptr<UnorderedList<int>> list = sptr<UnorderedList<int>>(new UnorderedList<int>());
    for (int i = 0; i < 4; ++i) {
        list->append(i);
    }
    int removed = list->remove(1);
    printf("Removed: %d\n", removed);
    for (int i = 0; i < list->getSize(); ++i) {
        printf("list val: %d\n", list->get(i));
    }
}



int main(int argc, char **argv) {
    runNewMain(0);
    return 0;
};
