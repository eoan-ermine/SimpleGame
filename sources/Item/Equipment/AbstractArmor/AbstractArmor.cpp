#include "AbstractArmor.h"

AbstractArmor::AbstractArmor(ArmorType type): AbstractEquipment("Default name", "Default description", EquipmentType::ARMOR), armorType(type) { }

AbstractArmor::AbstractArmor(std::string name, std::string description, ArmorType type): AbstractEquipment(name, description, EquipmentType::ARMOR), armorType(type) {}

void AbstractArmor::setPenetration(Penetration newPenetration) {
    this->armorInfo.penetration = newPenetration;
}
