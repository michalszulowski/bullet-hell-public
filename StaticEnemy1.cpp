#include "StaticEnemy1.h"
#include "LinearPattern.h"
#include "ExponentialPattern.h"
#include "SinusoidalPattern.h"

StaticEnemy1::StaticEnemy1(Coord startingPosition, sptr<Displayable> image, sptr<Displayable> shotSprite) : Enemy(startingPosition) {
    this->image = image;
    this->shotSprite = shotSprite;
    shootingPatterns = new ArrayList<sptr<ShootingPattern>>(2);
    shootingPatterns->append(new LinearPattern(shotSprite, this));
    shootingPatterns->append(new SinusoidalPattern(shotSprite, this));
    currentPattern = shootingPatterns->get(currentPatternIndex);
    changePatternFor = 5000;
    shotFor = 2000;
}

void StaticEnemy1::move(long inTime) {

}

SDL_Surface *StaticEnemy1::getImage(long time) {
    return image->getImage(time);
}

