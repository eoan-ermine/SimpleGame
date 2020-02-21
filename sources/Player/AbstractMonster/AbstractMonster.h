#pragma once

#include "../AbstractPlayer/AbstractPlayer.h"

class AbstractMonster: public AbstractPlayer {
public:
    AbstractMonster();
    AbstractMonster(int health);
    ~AbstractMonster();

};
