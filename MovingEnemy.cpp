#include "MovingEnemy.h"
#include "LinearPattern.h"
#include "ExponentialPattern.h"
#include "SinusoidalPattern.h"

MovingEnemy::MovingEnemy(Coord startingPosition, sptr<Displayable> image, sptr<Displayable> shotSprite,
                         int movingAreaWidth, int movingAreaHeight) : Enemy(startingPosition) {
    this->image = image;
    this->shotSprite = shotSprite;
    this->movingAreaWidth = movingAreaWidth;
    this->movingAreaHeight = movingAreaHeight;
    this->startingPosition = startingPosition;
    shootingPatterns = new ArrayList<sptr<ShootingPattern>>(2);
    shootingPatterns->append(new LinearPattern(shotSprite, this));
    shootingPatterns->append(new SinusoidalPattern(shotSprite, this));
    currentPattern = shootingPatterns->get(currentPatternIndex);
    changePatternFor = 5000;
    shotFor = 2000;
    distance = 0;
    state = E_MOVING;
    this->movementSpeedPerSecond = 2.0;
}

void MovingEnemy::move(long inTime) {
    double distToMove = getDistanceToMove(inTime);
    distance += distToMove;
    double x = (double) movingAreaWidth / 2.0 + sin(distance) * (double) movingAreaHeight / 3.0;
    double y = (double) movingAreaHeight / 2.0 + cos(distance) * (double) movingAreaWidth / 3.0;
    Coord dest = Coord(startingPosition.x + x,startingPosition.y + y);
    setPosition(dest);
}

SDL_Surface *MovingEnemy::getImage(long time) {
    return image->getImage(time);
}

