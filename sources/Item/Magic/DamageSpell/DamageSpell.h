#pragma once

#include <iostream>
#include "../AbstractMagic/AbstractMagic.h"

class DamageSpell final: public AbstractMagic {
public:
    DamageSpell();
    ~DamageSpell();

    void action(AbstractPlayer* lhs, AbstractPlayer* rhs) override;
};
