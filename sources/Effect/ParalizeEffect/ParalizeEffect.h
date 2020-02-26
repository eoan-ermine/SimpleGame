#pragma once

#include "../AbstractEffect.h"

class ParalizeEffect: public AbstractEffect {
public:
    ParalizeEffect(int duration);
    ~ParalizeEffect();

    void preAction(AbstractPlayer* ply) override;
    void afterAction(AbstractPlayer* ply) override;
};
