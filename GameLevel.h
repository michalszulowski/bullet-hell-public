#ifndef PROJ_2_BULLET_HELL_GAMELEVEL_H
#define PROJ_2_BULLET_HELL_GAMELEVEL_H

#include "sdlinclude.h"
#include "Player.h"
#include "sptr.h"
#include "Bullet.h"
#include "UnorderedList.h"
#include "IntDimensions.h"
#include "BmpResourceManager.h"
#include "Enemy.h"
#include "Timer.h"
#include "GameCamera.h"
#include "ImageRenderer.h"
#include "GamePerformanceMeasurer.h"
#include "LevelResult.h"
#include "AnimationLoader.h"

class GameCamera;

class GameLevel {
protected:
    sptr<BmpResourceManager> resourceManager;
    sptr<GameCamera> gameCamera;
    sptr<ImageRenderer> imageRenderer;
    bool running = false;
    sptr<Timer> timer;
    sptr<GamePerformanceMeasurer> performanceMeasurer;
    sptr<AnimationLoader> animationLoader;
    sptr<Player> player;
    sptr<Enemy> enemy;
    sptr<Displayable> background;
    sptr<UnorderedList<sptr<GameEntity>>> entities;
    sptr<UnorderedList<sptr<Bullet>>> enemyBullets;
    sptr<UnorderedList<sptr<Bullet>>> playerBullets;
    LevelResult result;

public:
    GameLevel(sptr<Displayable> background, sptr<BmpResourceManager> resourceManager,
              sptr<ImageRenderer> imageRenderer);
    void initialize();
    void startMainLoop();
    Coord getGraphicalCentre();
    sptr<UnorderedList<sptr<GameEntity>>> getEntities();
    sptr<Displayable> getBackground();
    sptr<Timer> getTimer();
    sptr<GamePerformanceMeasurer> getPerformanceMeasurer();
    sptr<Player> getPlayer();
    sptr<Enemy> getEnemy();
    LevelResult getResult();

protected:
    void initPlayer();
    virtual void initEnemy() = 0;

private:
    void performMainLoop();
    void moveEntities();
    void checkEnemyCollisions();
    void checkPlayerCollisions();
    void handleNewBullets(sptr<List<sptr<Bullet>>> bullets);
    void handlePlayerBullet(sptr<Bullet> bullet);
    void pullAndHandleEvents();
    void handleEvent(SDL_Event event);
    void handleKeyDown(SDL_Keycode key);
};


#endif //PROJ_2_BULLET_HELL_GAMELEVEL_H
