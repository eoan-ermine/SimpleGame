#pragma once

#include "../GameWindow/Game/GameObject/GameObject.h"

class AbstractPlayer;

class AbstractEffect: public GameObject {
private:
    int duration, last;
    bool permanent;
public:
    AbstractEffect(int duration);
    ~AbstractEffect();

    virtual void action(AbstractPlayer* ply);

    int getDuration() const noexcept;
    int getRemains() const noexcept;
    bool isPermanent() const noexcept;
};
