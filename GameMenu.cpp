#include "GameMenu.h"
#include "SdlUtils.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "StaticSprite.h"

GameMenu::GameMenu(sptr<ImageRenderer> imageRenderer, sptr<BmpResourceManager> resourceManager, SDL_Surface* charset) : imageRenderer(imageRenderer) {
    this->charset = charset;
    this->info = new CharSeq("witam w grze");
    sptr<Displayable> background = new StaticSprite(resourceManager->getResource(new CharSeq("./files/backgrounds/bg1.bmp")));
    this->backgroundImg = background->getImage(0);
    availableLevels = new ArrayList<sptr<GameLevel>>(3);
    availableLevels->append(new Level1(new StaticSprite(resourceManager->getResource(new CharSeq("./files/backgrounds/bg1.bmp"))), resourceManager, imageRenderer));
    availableLevels->append(new Level2(new StaticSprite(resourceManager->getResource(new CharSeq("./files/backgrounds/bg2.bmp"))), resourceManager, imageRenderer));
    availableLevels->append(new Level3(new StaticSprite(resourceManager->getResource(new CharSeq("./files/backgrounds/bg3.bmp"))), resourceManager, imageRenderer));
}

bool GameMenu::startMainLoop() {
    showAvailableLevels();
    running = true;
    while (running) {
        performMainLoop();
    }
    return exit;
}

void GameMenu::showAvailableLevels() {
    SDL_Surface* screen = imageRenderer->getImage();
    SdlUtils::drawSurface(screen, backgroundImg, 0 ,0);

    char* infoText = info->asArray();
    SdlUtils::drawString(screen, screen->w / 2 - strlen(infoText) * 8 / 2, 10, infoText, charset);

    char text[128];
    sprintf(text, "Kliknij 1, 2 lub 3 zeby wybrac poziom, albo Esc zeby wyjsc");
    SdlUtils::drawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 30, text, charset);
    printf("Levels shown\n");
    imageRenderer->renderImage();
}

void GameMenu::performMainLoop() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        handleEvent(event);
    };
}

void GameMenu::handleEvent(SDL_Event event) {
    switch(event.type) {
        case SDL_KEYDOWN:
            handleKeyDown(event.key.keysym.sym);
            break;
        case SDL_QUIT:
            running = false;
            exit = true;
            break;
    };
}

void GameMenu::setInfo(sptr<CharSeq> info) {
    this->info = info;
}

void GameMenu::handleKeyDown(SDL_Keycode key) {
    switch (key) {
        case SDLK_1:
            running = false;
            chosenLevel = availableLevels->get(0);
            break;
        case SDLK_2:
            chosenLevel = availableLevels->get(1);
            running = false;
            break;
        case SDLK_3:
            chosenLevel = availableLevels->get(2);
            running = false;
            break;
        case SDLK_ESCAPE:
            running = false;
            exit = true;
            break;
    }
}

sptr<GameLevel> GameMenu::getChosenLevel() {
    return chosenLevel;
}

bool GameMenu::getExit() {
    return exit;
}
