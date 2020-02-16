#include "AbstractEquipment.h"

AbstractEquipment::AbstractEquipment(): Item("Default name", "Default description", ItemType::EQUIPMENT) {
}

AbstractEquipment::AbstractEquipment(std::string name, std::string description): Item(name, description, ItemType::EQUIPMENT) {
}

AbstractEquipment::~AbstractEquipment() {
}

void AbstractEquipment::setEquipmentType(EquipmentType newType) {
    this->equipmentType = newType;
    if(equipmentType == EquipmentType::WEAPON) {
        if(armorType != ArmorType::NONE) {
            armorType = ArmorType::NONE;
        }
        armorInfo = {};
    } else {
        weaponInfo = {};
    }
}

void AbstractEquipment::setArmorType(ArmorType newType) {
    if(equipmentType != EquipmentType::WEAPON) {
        this->armorType = newType;
    }
}

void AbstractEquipment::setHitPoints(int newHitPoints) {
    if(newHitPoints > commonInfo.maxHitPoints) {
        this->commonInfo.hitPoints = this->commonInfo.maxHitPoints;
    } else {
        this->commonInfo.hitPoints = newHitPoints;
    }
}

void AbstractEquipment::setMaxHitPoints(int newMaxHitPoints) {
    if(newMaxHitPoints > commonInfo.maxHitPoints) {
        this->commonInfo.hitPoints = newMaxHitPoints;
    }
    this->commonInfo.maxHitPoints = newMaxHitPoints;
}

void AbstractEquipment::setMass(int newMass) {
    this->commonInfo.mass = newMass;
}

void AbstractEquipment::setPenetration(Penetration newPenetration) {
    if(equipmentType == EquipmentType::ARMOR) {
        newPenetration.sharp > 1 ? armorInfo.penetration.sharp = 1 : armorInfo.penetration.sharp = newPenetration.sharp;
        newPenetration.blunt > 1 ? armorInfo.penetration.blunt = 1 : armorInfo.penetration.blunt = newPenetration.blunt;
        newPenetration.heat > 1 ? armorInfo.penetration.heat = 1 : armorInfo.penetration.heat = newPenetration.heat;
    }
}

void AbstractEquipment::setDamage(float newDamage) {
    if(equipmentType == EquipmentType::WEAPON) {
        this->weaponInfo.damage = newDamage;
    }
}
