#include "AbstractEquipment.h"

#include "../../Player/AbstractPlayer/AbstractPlayer.h"
#include "../../Battle/BattleFormulas.h"

AbstractEquipment::AbstractEquipment(): Item("Default name", "Default description", ItemType::EQUIPMENT) {
}

AbstractEquipment::AbstractEquipment(std::string name, std::string description): Item(name, description, ItemType::EQUIPMENT) {
}

AbstractEquipment::~AbstractEquipment() {
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

EquipmentType AbstractEquipment::getEquipmentType() {
    return this->equipmentType;
}

ArmorType AbstractEquipment::getArmorType() {
    return this->armorType;
}

// To do
/*void AbstractEquipment::use(AbstractPlayer* lhs, AbstractPlayer* rhs) {
    int aAccuracy = lhs->getStat(StatType::ACCURACY);
    int vDodge = rhs->getStat(StatType::EVASION);
    if(BattleFormulas::hitSuccessful(aAccuracy, vDodge)) {
        int aMinHitValue=0, int aMaxHitValue=weaponInfo.damage, int vArmor=rhs.;
        rhs->changeStat(StatType::HEALTH, -(BattleFormulas::calculateDamage()))
    } else {

    }
}*/
