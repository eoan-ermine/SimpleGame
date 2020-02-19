#pragma once

#include "../AbstractEquipment.h"

class AbstractArmor: public AbstractEquipment {
private:
    ArmorType armorType;
    struct {
        Penetration penetration;
    } armorInfo;
public:
    AbstractArmor(ArmorType type);
    AbstractArmor(std::string name, std::string description, ArmorType type);
    virtual ~AbstractArmor();

    void setPenetration(Penetration newPenetration);

    ArmorType getArmorType();
    Penetration getPenetration();

    int calculateArmor();
};
