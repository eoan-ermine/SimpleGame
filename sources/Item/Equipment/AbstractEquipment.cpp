#include "AbstractEquipment.h"

#include "../../Player/AbstractPlayer/AbstractPlayer.h"
#include "../../Battle/BattleFormulas.h"

AbstractEquipment::AbstractEquipment(EquipmentType type): Item("Default name", "Default description", ItemType::EQUIPMENT) {
    this->equipmentType = type;
}

AbstractEquipment::AbstractEquipment(std::string name, std::string description, EquipmentType type): Item(name, description, ItemType::EQUIPMENT) {
    this->equipmentType = type;
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

EquipmentType AbstractEquipment::getEquipmentType() {
    return this->equipmentType;
}

int AbstractEquipment::getHitPoints() {
    return this->commonInfo.hitPoints;
}

int AbstractEquipment::getMaxHitPoints() {
    return this->commonInfo.maxHitPoints;
}

int AbstractEquipment::getMass() {
    return this->commonInfo.mass;
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
