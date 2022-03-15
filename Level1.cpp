#include "Level1.h"
#include "StaticSprite.h"
#include "StaticEnemy1.h"
#include "Animation.h"

Level1::Level1(sptr<Displayable> background, sptr<BmpResourceManager> resourceManager,
               sptr<ImageRenderer> imageRenderer) : GameLevel(background, resourceManager, imageRenderer) {

}

void Level1::initEnemy() {
    sptr<Displayable> sprite = new StaticSprite(resourceManager->getResource(new CharSeq("./files/enemies/red.bmp")));
    sptr<Displayable> bulletSprite = new StaticSprite(resourceManager->getResource(new CharSeq("./files/bullets/enemybullet.bmp")));
    enemy = new StaticEnemy1(Coord(), sprite, bulletSprite);
    enemy->setPosition({120, 120});
}