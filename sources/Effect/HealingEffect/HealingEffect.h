#pragma once

#include "../AbstractEffect.h"
#include "../../Utility/Utility.h"

class HealingEffect: public AbstractEffect {
public:
    HealingEffect(int duration);
    ~HealingEffect();

    void action(AbstractPlayer* ply) override;
};
