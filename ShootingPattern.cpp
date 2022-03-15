#include "ShootingPattern.h"
#include <math.h>

ShootingPattern::ShootingPattern(sptr<Displayable> bulletSprite, GameEntity* bulletSource) {
    this->bulletSprite = bulletSprite;
    this->bulletSource = bulletSource;
}

sptr<List<sptr<Bullet>>> ShootingPattern::generateBullets() {
    sptr<List<sptr<Bullet>>> bullets = new ArrayList<sptr<Bullet>>(numberOfBullets);
    for (int i = 0; i < numberOfBullets; ++i) {
        sptr<Bullet> bullet = createBullet(i);
        bullets->append(bullet);
    }
    return bullets;
}

double ShootingPattern::getAngleOfBullet(int ith) {
    double angle = ((double) ith / (double ) numberOfBullets) * 2*M_PI;
    return angle;
}
