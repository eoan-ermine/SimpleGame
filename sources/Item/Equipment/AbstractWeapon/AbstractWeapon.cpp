#include "AbstractWeapon.h"

AbstractWeapon::AbstractWeapon(WeaponType type): AbstractWeapon("Default name", "Default description", EquipmentType::WEAPON), weaponType(type) { }

AbstractWeapon::AbstractWeapon(std::string name, std::string description, WeaponType type): AbstractEquipment(name, description, EquipmentType::WEAPON), weaponType(type) {}

void AbstractWeapon::setDamage(float newDamage) {
    this->weaponInfo.damage = newDamage;
}
