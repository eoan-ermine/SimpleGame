#pragma once

#include "../AbstractEffect.h"
#include "../../Utility/Utility.h"

class BurningEffect: public AbstractEffect {
public:
    BurningEffect(int duration);
    ~BurningEffect();

    void action(AbstractPlayer* ply) override;
};
