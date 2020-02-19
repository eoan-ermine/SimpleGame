#include "AbstractWeapon.h"

#include "../../../Battle/BattleFormulas.h"
#include "../../../Player/AbstractPlayer/AbstractPlayer.h"

AbstractWeapon::AbstractWeapon(WeaponType type): AbstractEquipment("Default name", "Default description", EquipmentType::WEAPON) {
    this->weaponType = type;
}

AbstractWeapon::AbstractWeapon(std::string name, std::string description, WeaponType type): AbstractEquipment(name, description, EquipmentType::WEAPON), weaponType(type) {
    this->weaponType = type;
}

void AbstractWeapon::setDamage(float newDamage) {
    this->weaponInfo.damage = newDamage;
}

WeaponType AbstractWeapon::getWeaponType() {
    return this->weaponType;
}

float AbstractWeapon::getDamage() {
    return this->weaponInfo.damage;
}

void AbstractWeapon::use(AbstractPlayer* lhs, AbstractPlayer* rhs) {
    int aAccuracy = lhs->getStat(StatType::ACCURACY), vDodge = rhs->getStat(StatType::EVASION);
    if(BattleFormulas::hitSuccessful(aAccuracy, vDodge)) {
        int aMinHitValue = 0, aMaxHitValue = this->getDamage(), vArmor = rhs->getStat(StatType::ARMOR);
        if(int damage = BattleFormulas::calculateDamage(aMinHitValue, aMaxHitValue, vArmor); damage != 0) {
            rhs->changeStat(StatType::HEALTH, -damage);
        }
    }
}
