#pragma once

#include "../../Item.h"

class AbstractMagic: public Item {
private:
    int manaCost, cooldown;
public:
    AbstractMagic(int manaCost, int cooldown);
    AbstractMagic(std::string name, std::string description, int manaCost, int cooldown);

    int getManaCost();
    int getCooldown();

    virtual void action(AbstractPlayer* lhs, AbstractPlayer* rhs);
    void use(AbstractPlayer* lhs, AbstractPlayer* rhs) override;
};
