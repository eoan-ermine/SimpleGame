#include "AbstractMagic.h"

#include "../../../Player/AbstractPlayer/AbstractPlayer.h"
#include "../../SpellsDeck/SpellsDeck.h"

AbstractMagic::AbstractMagic(int manaCost, int coolDown): Item("Default name", "Default description", ItemType::MAGIC) {
    this->manaCost = manaCost;
    this->cooldown = cooldown;
}

AbstractMagic::AbstractMagic(std::string name, std::string description, int manaCost, int cooldown): Item(name, description, ItemType::MAGIC) {
    this->manaCost = manaCost;
    this->cooldown = cooldown;
}

int AbstractMagic::getManaCost() {
    return manaCost;
}

int AbstractMagic::getCooldown() {
    return cooldown;
}

void AbstractMagic::action(AbstractPlayer* lhs, AbstractPlayer* rhs) { }

void AbstractMagic::use(AbstractPlayer* lhs, AbstractPlayer* rhs) {
    SpellsDeck& spellsDeck = lhs->getSpells();
    this->action(lhs, rhs);
    lhs->changeStat(StatType::MANA, -manaCost);
    spellsDeck.spellCasted(this);
}
