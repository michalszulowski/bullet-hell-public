#ifndef PROJ_2_BULLET_HELL_GAMECAMERA_H
#define PROJ_2_BULLET_HELL_GAMECAMERA_H

#include "sdlinclude.h"
#include "GameLevel.h"
#include "IntCoord.h"
#include "Timer.h"

class GameLevel;

class GameCamera {
private:
    GameLevel* physicalSource;
    SDL_Surface* graphicalTarget;
    SDL_Surface* charset;
    sptr<BmpResourceManager> resourceManager;
    SDL_Surface* grade1;
    SDL_Surface* grade2;
    int black;
    int green;
    int red;
    int blue;

public:
    GameCamera(GameLevel* physicalSource, SDL_Surface* graphicalTarget, SDL_Surface* charset, sptr<BmpResourceManager> resourceManager);
    ~GameCamera() {};
    void drawLevelOnTarget();

private:
    void drawEntity(sptr<GameEntity> entity, IntCoord topLeftCorner);
    void drawBackground(IntCoord topLeftCorner);
    void drawInfoRect();
    void drawLifeBars();
    IntCoord getTopLeftCorner();
    IntCoord getAdjusted(Coord centre, IntCoord toCorner);

};


#endif //PROJ_2_BULLET_HELL_GAMECAMERA_H
