#pragma once

#include "../AbstractEquipment.h"

class AbstractPlayer;

class AbstractWeapon: public AbstractEquipment {
private:
    WeaponType weaponType;
    struct {
        float damage;
    } weaponInfo;
public:
    AbstractWeapon(WeaponType type);
    AbstractWeapon(std::string name, std::string description, WeaponType type);
    virtual ~AbstractWeapon();

    void setDamage(float newDamage);

    WeaponType getWeaponType();
    float getDamage();

    virtual void use(AbstractPlayer* lhs, AbstractPlayer* rhs) override;
};
