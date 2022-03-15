#include "Level2.h"
#include "StaticSprite.h"
#include "StaticEnemy2.h"
#include "Animation.h"

Level2::Level2(sptr<Displayable> background, sptr<BmpResourceManager> resourceManager,
               sptr<ImageRenderer> imageRenderer) : GameLevel(background, resourceManager, imageRenderer) {

}

void Level2::initEnemy() {
    sptr<Displayable> sprite = new StaticSprite(resourceManager->getResource(new CharSeq("./files/enemies/red.bmp")));
    sptr<Displayable> bulletSprite = new StaticSprite(resourceManager->getResource(CharSeq::getSptr("./files/bullets/enemybullet.bmp")));
    enemy = new StaticEnemy2(Coord(), sprite, bulletSprite);
    enemy->setPosition({120, 120});
}