#pragma once

class AbstractPlayer;

class AbstractEffect {
private:
    int duration;
public:
    AbstractEffect(int duration);
    ~AbstractEffect();

    virtual void action(AbstractPlayer* ply) = 0;
    int getDuration();
};
