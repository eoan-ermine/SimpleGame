#include "AbstractWeapon.h"

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
