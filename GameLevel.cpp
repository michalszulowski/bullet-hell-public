#include "GameLevel.h"
#include "StaticSprite.h"
#include "LinearBullet.h"


GameLevel::GameLevel(sptr<Displayable> background, sptr<BmpResourceManager> resourceManager,
                     sptr<ImageRenderer> imageRenderer) {
    this->background = background;
    this->resourceManager = resourceManager;
    this->imageRenderer = imageRenderer;
    this->animationLoader = new AnimationLoader(resourceManager);
    timer = new Timer();
    performanceMeasurer = new GamePerformanceMeasurer(timer);
    entities = new UnorderedList<sptr<GameEntity>>(100);
    enemyBullets = new UnorderedList<sptr<Bullet>>(300);
    playerBullets = new UnorderedList<sptr<Bullet>>(100);
    SDL_Surface* charset = resourceManager->getResource(new CharSeq("./files/util/charset.bmp"));
    gameCamera = new GameCamera(this, imageRenderer->getImage(), charset, resourceManager);
}


void GameLevel::initialize() {
    initPlayer();
    initEnemy();
    sptr<GameEntity> playerPointer;
    playerPointer.copyFrom(player.getContent(), player.getNumberOfReferences());
    entities->append(playerPointer);
    sptr<GameEntity> enemyPointer;
    enemyPointer.copyFrom(enemy.getContent(), enemy.getNumberOfReferences());
    entities->append(enemyPointer);
}

void GameLevel::startMainLoop() {
    running = true;
    timer->startCounting(SDL_GetTicks());
    while (running) {
        performMainLoop();
        performanceMeasurer->updateAfterLoop();
    }
}


void GameLevel::performMainLoop() {
    timer->updateTime(SDL_GetTicks());
    sptr<List<sptr<Bullet>>> newBullets = enemy->shoot(timer->getFromStart());
    handleNewBullets(newBullets);
    moveEntities();
    checkEnemyCollisions();
    checkPlayerCollisions();
    gameCamera->drawLevelOnTarget();
    imageRenderer->renderImage();
    pullAndHandleEvents();
}

void GameLevel::handleNewBullets(sptr<List<sptr<Bullet>>> newBullets) {
    for (int i = 0; i < newBullets->getSize(); ++i) {
        sptr<Bullet> bullet = newBullets->get(i);
        enemyBullets->append(bullet);
        sptr<GameEntity> entityPointer;
        entityPointer.copyFrom(bullet.getContent(), bullet.getNumberOfReferences());
        entities->append(entityPointer);
    }
}

void GameLevel::pullAndHandleEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        handleEvent(event);
    };
}

void GameLevel::handleEvent(SDL_Event event) {
    switch(event.type) {
        case SDL_KEYDOWN:
            handleKeyDown(event.key.keysym.sym);
            break;
        case SDL_KEYUP:
            player->setState(STANDING);
            break;
        case SDL_QUIT:
            running = false;
            break;
    };
}

void GameLevel::handleKeyDown(SDL_Keycode key) {
    switch (key) {
        case SDLK_ESCAPE:
            running = false;
            result = G_EXIT;
            break;
        case SDLK_UP:
            player->setState(MOVING_UP);
            break;
        case SDLK_DOWN:
            player->setState(MOVING_DOWN);
            break;
        case SDLK_LEFT:
            player->setState(MOVING_LEFT);
            break;
        case SDLK_RIGHT:
            player->setState(MOVING_RIGHT);
            break;
        case SDLK_q:
            handlePlayerBullet(player->shoot(timer->getFromStart()));
            break;
    }
}

void GameLevel::handlePlayerBullet(sptr<Bullet> bullet) {
    playerBullets->append(bullet);
    sptr<GameEntity> entityPointer;
    entityPointer.copyFrom(bullet.getContent(), bullet.getNumberOfReferences());
    entities->append(entityPointer);
}

Coord GameLevel::getGraphicalCentre() {
    return player->getCentre();
}

sptr<UnorderedList<sptr<GameEntity>>> GameLevel::getEntities() {
    return entities;
}

sptr<Displayable> GameLevel::getBackground() {
    return background;

}

void GameLevel::moveEntities() {
    for (int i = 0; i < entities->getSize(); ++i) {
        entities->get(i)->move(timer->getDelta());
    }
}

sptr<Timer> GameLevel::getTimer() {
    return timer;
}

sptr<GamePerformanceMeasurer> GameLevel::getPerformanceMeasurer() {
    return performanceMeasurer;
}

void GameLevel::checkEnemyCollisions() {
    for (int i = 0; i < playerBullets->getSize(); ++i) {
        sptr<Bullet> bullet = playerBullets->get(i);
        sptr<GameEntity> entityPointer;
        entityPointer.copyFrom(bullet.getContent(), bullet.getNumberOfReferences());
        if (enemy->doesTouch(entityPointer)) {
            enemy->receiveShot(bullet->getPower(), timer->getFromStart());
            player->addPoints(bullet->getPower(), timer->getFromStart());
            bullet->deactivate();
            if (enemy->getLifeFactor() <= 0) {
                running = false;
                result = PLAYER_WON;
            }
        }
    }
}

void GameLevel::checkPlayerCollisions() {
    for (int i = 0; i < enemyBullets->getSize(); ++i) {
        sptr<Bullet> bullet = enemyBullets->get(i);
        sptr<GameEntity> entityPointer;
        entityPointer.copyFrom(bullet.getContent(), bullet.getNumberOfReferences());
        if (player->doesTouch(entityPointer)) {
            player->receiveShot(bullet->getPower(), timer->getFromStart());
            player->addPoints(-(bullet->getPower()), timer->getFromStart());
            bullet->deactivate();
            if (player->getLifeFactor() <= 0) {
                running = false;
                result = ENEMY_WON;
            }
        }
    }
}

sptr<Player> GameLevel::getPlayer() {
    return player;
}

sptr<Enemy> GameLevel::getEnemy() {
    return enemy;
}

void GameLevel::initPlayer() {
    sptr<Displayable> sprite = new StaticSprite(resourceManager->getResource(new CharSeq("./files/enemies/red.bmp")));
    sptr<Displayable> bulletSprite = new StaticSprite(resourceManager->getResource(new CharSeq("./files/bullets/playerbullet.bmp")));
    player = new Player(sprite, bulletSprite);
    sptr<Displayable> standingAnimation = this->animationLoader->
            loadOf(new CharSeq("./files/player/static1.bmp"), new CharSeq("./files/player/static2.bmp"), 500);
    player->setStandingDisplayable(standingAnimation);

    player->setMovingRightDisplayable(animationLoader->
            loadOf(new CharSeq("./files/player/right1.bmp"), new CharSeq("./files/player/right2.bmp"), 500));

    player->setMovingDownDisplayable(animationLoader->
            loadOf(new CharSeq("./files/player/down1.bmp"), new CharSeq("./files/player/down2.bmp"), 500));

    player->setMovingLeftDisplayable(animationLoader->
            loadOf(new CharSeq("./files/player/left1.bmp"), new CharSeq("./files/player/left2.bmp"), 500));

    player->setMovingUpDisplayable(animationLoader->
            loadOf(new CharSeq("./files/player/up1.bmp"), new CharSeq("./files/player/up2.bmp"), 500));

    player->setPosition({0, 0});
}

LevelResult GameLevel::getResult() {
    return result;
}
