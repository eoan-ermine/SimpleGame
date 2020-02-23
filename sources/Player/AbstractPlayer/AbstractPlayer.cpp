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


void AbstractPlayer::setMaze(AbstractMaze* newMaze) noexcept {
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

bool AbstractPlayer::wearEquipment(AbstractWeapon* weapon) {
    if(inventory.contains(weapon)) {
        WeaponType weaponType = weapon->getWeaponType();
        if(weaponType == WeaponType::FIRST) {
            this->wearedEquipment.weapon.first = weapon;
        }
        return true;
    } else {
        return false;
    }
}

bool AbstractPlayer::wearEquipment(AbstractArmor* armor) {
    if(inventory.contains(armor)) {
        ArmorType armorType = armor->getArmorType();

        if(armorType == ArmorType::HEAD) {
            this->wearedEquipment.armor.head = armor;
        } else if(armorType == ArmorType::BODY) {
            this->wearedEquipment.armor.body = armor;
        } else if(armorType == ArmorType::LEGS) {
            this->wearedEquipment.armor.legs = armor;
        } else if(armorType == ArmorType::BOOTS) {
            this->wearedEquipment.armor.boots = armor;
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

AbstractMaze* AbstractPlayer::getMaze() const {
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
    case StatType::MANA:
        this->stats.mana = value;
        break;
    case StatType::MAX_MANA:
        this->stats.maxMana = value;
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
    case StatType::MANA:
        this->stats.mana += value;
        break;
    case StatType::MAX_MANA:
        this->stats.maxMana += value;
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
    case StatType::MAX_HUNGER:
        return this->stats.maxHunger;
    case StatType::ARMOR:
        return (wearedEquipment.armor.head->calculateArmor() + wearedEquipment.armor.body->calculateArmor() + wearedEquipment.armor.legs->calculateArmor() + wearedEquipment.armor.boots->calculateArmor()) / 2;
    case StatType::MANA:
        return this->stats.mana;
    case StatType::MAX_MANA:
        return this->stats.maxMana;
    default:
        return 0;
    }
}

bool AbstractPlayer::dropItem(Item* item) noexcept {
    if(inventory.contains(item)) {
        inventory.deleteItem(item);
        this->getRoom()->getInventory()->addItem(item);
        return true;
    }
    return false;
}

bool AbstractPlayer::getItem(Item* item) noexcept {
    if(Inventory* inv = this->getRoom()->getInventory(); inv->contains(item)) {
        inv->deleteItem(item);
        inventory.addItem(item);
        return true;
    }
    return false;
}

std::vector<AbstractEffect*>& AbstractPlayer::getEffects() noexcept {
    return effects;
}

void AbstractPlayer::addEffect(AbstractEffect* effect) noexcept {
    effects.push_back(effect);
}

void AbstractPlayer::deleteEffect(AbstractEffect* effect) noexcept {
    if(auto it = std::find(effects.begin(), effects.end(), effect); it != effects.end()) {
        effects.erase(it);
    }
}

SpellsDeck& AbstractPlayer::getSpells() noexcept {
    return spells;
}

void AbstractPlayer::castSpell(std::string spellName, AbstractPlayer* victim) noexcept {
	if(this->canCast(spell)) {
		this->spells.cast(spells[spellName], this, victim);
	}
}

void AbstractPlayer::castSpell(AbstractMagic* spell, AbstractPlayer* victim) noexcept {
    if(this->canCast(spell)) {
		this->spells.cast(spell, this, victim);
    }
}

bool AbstractPlayer::canCast(AbstractMagic* spell) noexcept {
    if(spells.contains(spell) and spells.getCooldown(spell) == 0 and stats.mana > spell->getManaCost()) {
        return true;
    }
    return false;
}
