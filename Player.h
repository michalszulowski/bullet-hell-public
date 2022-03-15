#ifndef PROJ_2_BULLET_HELL_PLAYER_H
#define PROJ_2_BULLET_HELL_PLAYER_H

#include "PlayerState.h"
#include "DieableEntity.h"
#include "LinearBullet.h"

class Player : public DieableEntity {
private:
    PlayerState state;
    PlayerState direction;
    long lastTimeShot;
    long invincibilityTime;
    sptr<Displayable> bulletSprite;
    sptr<Displayable> currentSprite;
    sptr<Displayable> standingDisplayable;
    sptr<Displayable> movingRightDisplayable;
    sptr<Displayable> movingDownDisplayable;
    sptr<Displayable> movingLeftDisplayable;
    sptr<Displayable> movingUpDisplayable;
    int points = 0;

public:
    Player(sptr<Displayable> image, sptr<Displayable> bulletSprite);
    void setState(PlayerState state);
    void move(long inTime);
    SDL_Surface* getImage(long time);
    sptr<Bullet> shoot(long atTime);
    void setStandingDisplayable(sptr<Displayable> displayable);
    void setMovingRightDisplayable(sptr<Displayable> displayable);
    void setMovingDownDisplayable(sptr<Displayable> displayable);
    void setMovingLeftDisplayable(sptr<Displayable> displayable);
    void setMovingUpDisplayable(sptr<Displayable> displayable);
    void receiveShot(double power, long atTime);
    int getPoints();
    void addPoints(double basicValue, long time);

private:
    sptr<Displayable> getDisplayableOfState();
};


#endif //PROJ_2_BULLET_HELL_PLAYER_H
