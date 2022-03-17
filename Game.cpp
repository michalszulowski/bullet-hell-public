#include "Game.h"

Game::Game() {
    imageRenderer = new ImageRenderer(1500, 1000, "Testowy poziom");
    resourceManager = new BmpResourceManager();
    charset = resourceManager->getResource(new CharSeq("./files/util/charset.bmp"));
    lastLevelResult = G_EXIT;
}

void Game::start() {
    imageRenderer->openWindow();
    startMainLoop();
}

void Game::startMainLoop() {
    do {
        menu = new GameMenu(imageRenderer, resourceManager, charset);
        menu->setInfo(getInfoDependingOn(lastLevelResult));
        menu->startMainLoop();
        if (menu->getExit()) {
            break;
        }
        handleChosenLevel();
    } while (!menu->getExit());
}

sptr<CharSeq> Game::getInfoDependingOn(LevelResult result) {
    if (result == PLAYER_WON) {
        return new CharSeq("Gratulacje, wygrales, sprobuj nowy poziom");
    } else if (result == ENEMY_WON) {
        return new CharSeq("Niestety przegrales, sprobuj jeszcze raz");
    }
    return new CharSeq("witamy w grze");
};

void Game::handleChosenLevel() {
    sptr<GameLevel> level = menu->getChosenLevel();
    level->initialize();
    level->startMainLoop();
    lastLevelResult = level->getResult();
}

Game::~Game() {
    resourceManager->freeResources();
    imageRenderer->destroyResources();
}
