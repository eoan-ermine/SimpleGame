#pragma once

#include "../../Item.h"

class AbstractPlayer;
class AbstractEffect;

class AbstractEffectPotion: public Item {
private:
    AbstractEffect* effect;
public:
    AbstractEffectPotion(AbstractEffect* effect);
    AbstractEffectPotion(std::string name, std::string description, AbstractEffect* effect);

    void setEffect(AbstractEffect* newEffect);
    AbstractEffect* getEffect(AbstractEffect* newEffect);

    virtual void use(AbstractPlayer* lhs, AbstractPlayer* rhs) override;
};
