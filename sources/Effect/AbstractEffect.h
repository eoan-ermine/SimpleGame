#pragma once

class AbstractPlayer;

class AbstractEffect {
private:
    int duration, remain;
public:
    AbstractEffect(int duration);
    ~AbstractEffect();

    virtual void action(AbstractPlayer* ply) = 0;
};
