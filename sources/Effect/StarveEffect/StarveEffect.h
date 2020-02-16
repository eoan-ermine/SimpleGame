#pragma once

#include "../AbstractEffect.h"
#include "../../Utility/Utility.h"

class StarveEffect: public AbstractEffect {
public:
    StarveEffect(int duration);
    ~StarveEffect();

    void action(AbstractPlayer* ply) override;
};
