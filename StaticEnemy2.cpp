#include "StaticEnemy2.h"
#include "LinearPattern.h"
#include "ExponentialPattern.h"
#include "SinusoidalPattern.h"

StaticEnemy2::StaticEnemy2(Coord startingPosition, sptr<Displayable> image, sptr<Displayable> shotSprite) : Enemy(startingPosition) {
    this->image = image;
    this->shotSprite = shotSprite;
    shootingPatterns = new ArrayList<sptr<ShootingPattern>>(2);
    shootingPatterns->append(new SinusoidalPattern(shotSprite, this));
    shootingPatterns->append(new ExponentialPattern(shotSprite, this));
    currentPattern = shootingPatterns->get(currentPatternIndex);
    changePatternFor = 5000;
    shotFor = 2000;
}

void StaticEnemy2::move(long inTime) {

}

SDL_Surface *StaticEnemy2::getImage(long time) {
    return image->getImage(time);
}

