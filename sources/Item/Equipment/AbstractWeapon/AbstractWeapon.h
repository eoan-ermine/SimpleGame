#pragma once

#include "../AbstractEquipment.h"

class AbstractWeapon: public AbstractEquipment {
private:
    WeaponType weaponType;
    struct {
        float damage;
    } weaponInfo;
public:
    AbstractWeapon(WeaponType type);
    AbstractWeapon(std::string name, std::string description, WeaponType type);
    ~AbstractWeapon();

    void setDamage(float newDamage);
};
