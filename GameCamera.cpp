#include "GameCamera.h"
#include "SdlUtils.h"
#include <iostream>

GameCamera::GameCamera(GameLevel* physicalSource, SDL_Surface *graphicalTarget, SDL_Surface* charset, sptr<BmpResourceManager> resourceManager) {
    this->physicalSource = physicalSource;
    this->graphicalTarget = graphicalTarget;
    this->charset = charset;
    this->resourceManager = resourceManager;
    grade1 = resourceManager->getResource(new CharSeq("./files/grades/1.bmp"));
    grade2 = resourceManager->getResource(new CharSeq("./files/grades/2.bmp"));
    black = SDL_MapRGB(graphicalTarget->format, 0x00, 0x00, 0x00);
    green = SDL_MapRGB(graphicalTarget->format, 0x00, 0xFF, 0x00);
    red = SDL_MapRGB(graphicalTarget->format, 0xFF, 0x00, 0x00);
    blue = SDL_MapRGB(graphicalTarget->format, 0x11, 0x11, 0xCC);
}

void GameCamera::drawLevelOnTarget() {
    IntCoord topLeftCorner = getTopLeftCorner();
    drawBackground(topLeftCorner);
    sptr<UnorderedList<sptr<GameEntity>>> entities = physicalSource->getEntities();
    for (int i = 0; i < entities->getSize(); ++i) {
        sptr<GameEntity> entity = entities->get(i);
        drawEntity(entity, topLeftCorner);
    }
    drawInfoRect();
    drawLifeBars();
}

void GameCamera::drawEntity(sptr<GameEntity> entity, IntCoord topLeftCorner) {
    IntCoord centre = getAdjusted(entity->getCentre(), topLeftCorner);
    long time = physicalSource->getTimer()->getFromStart();
    SdlUtils::drawSurface(graphicalTarget, entity->getImage(time), centre.x, centre.y);
}

void GameCamera::drawBackground(IntCoord topLeftCorner) {
    long time = physicalSource->getTimer()->getFromStart();
    SDL_Surface* background = physicalSource->getBackground()->getImage(time);
    Coord bgCentre = Coord();
    bgCentre.x = background->w / 2;
    bgCentre.x = background->h / 2;
    IntCoord adjustedCentre = getAdjusted(bgCentre, topLeftCorner);
    SdlUtils::drawSurface(graphicalTarget, background, adjustedCentre.x, adjustedCentre.y);
}

IntCoord GameCamera::getTopLeftCorner() {
    Coord centre = physicalSource->getGraphicalCentre();
    int x = centre.x - graphicalTarget->w / 2;
    int y = centre.y - graphicalTarget->h / 2;
    IntCoord topLeftCorner = {x, y};
    return topLeftCorner;
}

IntCoord GameCamera::getAdjusted(Coord centre, IntCoord toCorner) {
    int x = centre.x - toCorner.x;
    int y = centre.y - toCorner.y;
    return {x, y};
}

void GameCamera::drawInfoRect() {
    char text[128];
    SdlUtils::drawRectangle(graphicalTarget, 4, 4, graphicalTarget->w - 8, 36, red, blue);
    sprintf(text, "Szablon drugiego zadania, czas trwania = %.1lf s  %.0lf klatek / s",
            (double) physicalSource->getTimer()->getFromStart() / 1000, physicalSource->getPerformanceMeasurer()->getFps());
    SdlUtils::drawString(graphicalTarget, graphicalTarget->w / 2 - strlen(text) * 8 / 2, 10, text, charset);
    sprintf(text, "Esc - wyjscie, \030, \031, \032, \033 - poruszanie, Q - strzelanie");
    SdlUtils::drawString(graphicalTarget, graphicalTarget->w / 2 - strlen(text) * 8 / 2, 26, text, charset);
}

void GameCamera::drawLifeBars() {
    const int B_WIDTH = 100;
    const int B_HEIGHT = 20;
    const int Y_CORNER = 50;
    const int SPACE_FROM_BOUNDARY = 10;

    char text[128];
    sprintf(text, "punkty: %d", physicalSource->getPlayer()->getPoints());

    SdlUtils::drawString(graphicalTarget, graphicalTarget->w / 5 - strlen(text) * 8 / 2, Y_CORNER, text, charset);

    SdlUtils::drawPartiallyFilledRectangle(graphicalTarget,
                                           physicalSource->getPlayer()->getLifeFactor(), SPACE_FROM_BOUNDARY,
                                           Y_CORNER,B_WIDTH, B_HEIGHT, black, green, red);
    SdlUtils::drawPartiallyFilledRectangle(graphicalTarget,
                                           physicalSource->getEnemy()->getLifeFactor(),
                                           graphicalTarget->w - SPACE_FROM_BOUNDARY - B_WIDTH,
                                           Y_CORNER,B_WIDTH, B_HEIGHT, black, green, red);
    SDL_Surface* grade;
    const int SUPER_GRADE_THRESHOLD = 50;
    if (physicalSource->getPlayer()->getPoints() > SUPER_GRADE_THRESHOLD) {
        grade = grade2;
    } else {
        grade = grade1;
    }
    SdlUtils::drawSurface(graphicalTarget, grade, graphicalTarget->w / 2, Y_CORNER + 100);
}
