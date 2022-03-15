#include "Level3.h"
#include "StaticSprite.h"
#include "MovingEnemy.h"
#include "Animation.h"

Level3::Level3(sptr<Displayable> background, sptr<BmpResourceManager> resourceManager,
               sptr<ImageRenderer> imageRenderer) : GameLevel(background, resourceManager, imageRenderer) {

}

void Level3::initEnemy() {
    sptr<Displayable> sprite = this->animationLoader->
            loadOf(new CharSeq("./files/enemies/red.bmp"), new CharSeq("./files/enemies/purple.bmp"), 500);
    sptr<Displayable> bulletSprite = new StaticSprite(resourceManager->getResource(new CharSeq("./files/bullets/enemybullet.bmp")));
    enemy = new MovingEnemy(Coord(), sprite, bulletSprite, 200, 200);
    enemy->setPosition({50, 50});
}