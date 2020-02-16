#include "AbstractPlayer.h"

AbstractPlayer::AbstractPlayer(): AbstractPlayer(100, 100) {
}


AbstractPlayer::AbstractPlayer(float health, float hunger) {
    this->stats.health = health;
    this->stats.hunger = hunger;

    effects.push_back(new StarveEffect(0));
}

AbstractPlayer::~AbstractPlayer() {
}


void AbstractPlayer::setMaze(Maze* newMaze) noexcept {
    this->currentMaze = newMaze;
}

void AbstractPlayer::setRoom(AbstractRoom* newRoom) noexcept {
    this->currentRoom = newRoom;
}

Inventory* AbstractPlayer::getInventory() noexcept {
    return &(this->inventory);
}

void AbstractPlayer::tick() noexcept {
    for(AbstractEffect* effect: effects) {
        effect->action(this);
    }
}

bool AbstractPlayer::wearEquipment(AbstractEquipment* equipment) {
    if(inventory.contains(equipment)) {
        EquipmentType equipmentType = equipment->getEquipmentType();
        ArmorType armorType = equipment->getArmorType();

        if(equipmentType == EquipmentType::WEAPON) {
            this->wearedEquipment.weapon.first = equipment;
        } else {
            if(armorType == ArmorType::HEAD) {
                this->wearedEquipment.armor.head = equipment;
            } else if(armorType == ArmorType::BODY) {
                this->wearedEquipment.armor.body = equipment;
            } else if(armorType == ArmorType::LEGS) {
                this->wearedEquipment.armor.legs = equipment;
            } else if(armorType == ArmorType::BOOTS) {
                this->wearedEquipment.armor.boots = equipment;
            }
        }
        return true;
    } else {
        return false;
    }
}

void AbstractPlayer::unwearEquipment(EquipmentType equipmentType, ArmorType armorType) {
    if(equipmentType == EquipmentType::WEAPON) {
        this->wearedEquipment.weapon.first = nullptr;
    } else {
        if(armorType == ArmorType::HEAD) {
            this->wearedEquipment.armor.head = nullptr;
        } else if(armorType == ArmorType::BODY) {
            this->wearedEquipment.armor.body = nullptr;
        } else if(armorType == ArmorType::LEGS) {
            this->wearedEquipment.armor.legs = nullptr;
        } else if(armorType == ArmorType::BOOTS) {
            this->wearedEquipment.armor.boots = nullptr;
        }
    }
}

Maze* AbstractPlayer::getMaze() const {
    return this->currentMaze;
}

AbstractRoom* AbstractPlayer::getRoom() const {
    return this->currentRoom;
}

bool AbstractPlayer::setStat(StatType stat, int value) noexcept {
    switch(stat) {
    case StatType::ACCURACY:
        this->stats.accuracy = value;
        break;
    case StatType::EVASION:
        this->stats.evasion = value;
        break;
    case StatType::STRENGTH:
        this->stats.strength = value;
        break;
    case StatType::EXPERIENCE:
        this->stats.experience = value;
        break;
    case StatType::LEVEL:
        this->stats.level = value;
        break;
    default:
        return false;
    }
    return true;
}

bool AbstractPlayer::setStat(StatType stat, float value) noexcept {
    switch(stat) {
    case StatType::HEALTH:
        this->stats.health = value;
        break;
    case StatType::HUNGER:
        this->stats.hunger = value;
        break;
    case StatType::MAX_HEALTH:
        this->stats.maxHealth = value;
        break;
    case StatType::MAX_HUNGER:
        this->stats.maxHunger = value;
        break;
    default:
        return false;
    }
    return true;
}

bool AbstractPlayer::changeStat(StatType stat, int value) noexcept {
    switch(stat) {
    case StatType::ACCURACY:
        this->stats.accuracy += value;
        break;
    case StatType::EVASION:
        this->stats.evasion += value;
        break;
    case StatType::STRENGTH:
        this->stats.strength += value;
        break;
    case StatType::EXPERIENCE:
        this->stats.experience += value;
        break;
    case StatType::LEVEL:
        this->stats.level += value;
        break;
    default:
        return false;
    }
    return true;
}

bool AbstractPlayer::changeStat(StatType stat, float value) noexcept {
    switch(stat) {
    case StatType::HEALTH:
        this->stats.health += value;
        break;
    case StatType::HUNGER:
        this->stats.hunger += value;
        break;
    case StatType::MAX_HEALTH:
        this->stats.maxHealth += value;
        break;
    case StatType::MAX_HUNGER:
        this->stats.maxHunger += value;
        break;
    default:
        return false;
    }
    return true;
}

float AbstractPlayer::getStat(StatType stat) const noexcept {
    switch(stat) {
    case StatType::ACCURACY:
        return this->stats.accuracy;
    case StatType::EVASION:
        return this->stats.evasion;
    case StatType::STRENGTH:
        return this->stats.strength;
    case StatType::EXPERIENCE:
        return this->stats.experience;
    case StatType::LEVEL:
        return this->stats.level;
    case StatType::HEALTH:
        return this->stats.health;
    case StatType::HUNGER:
        return this->stats.hunger;
    case StatType::MAX_HEALTH:
        return this->stats.maxHealth;
        break;
    case StatType::MAX_HUNGER:
        return this->stats.maxHunger;
        break;
    default:
        return 0;
    }
}
