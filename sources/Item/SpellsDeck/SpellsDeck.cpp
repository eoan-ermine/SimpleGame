#include "SpellsDeck.h"

SpellsDeck::SpellsDeck() { }

SpellsDeck::~SpellsDeck() { }

std::unordered_map<AbstractMagic*, int>& SpellsDeck::getSpells() noexcept {
    return this->spells;
}

void SpellsDeck::addSpell(AbstractMagic* spell) noexcept {
    this->spells.insert({spell, 0});
}

void SpellsDeck::deleteSpell(AbstractMagic* spell) noexcept {
    this->spells.erase(spell);
}

void SpellsDeck::spellCasted(AbstractMagic* spell) noexcept {
    this->spells[spell] = spell->getCooldown();
}

bool SpellsDeck::contains(AbstractMagic* key) const noexcept {
    return spells.find(key) != spells.end();
}

bool SpellsDeck::contains(std::string name) const noexcept  {
    auto predicate = [&name](auto pair) {
        return pair.first->getName() == name;
    };
    return std::find_if(spells.begin(), spells.end(), predicate) != spells.end();
}

AbstractMagic* SpellsDeck::getSpell(std::string name) noexcept {
    auto predicate = [&name](auto pair) {
        return pair.first->getName() == name;
    };
    if(auto it = std::find_if(spells.begin(), spells.end(), predicate); it != spells.end()) {
        return (*it).first;
    } else {
        throw std::runtime_error("Can't find spell with provided name");
    }
}

AbstractMagic* SpellsDeck::operator[](std::string name) noexcept {
    auto predicate = [&name](auto pair) {
        return pair.first->getName() == name;
    };
    auto it = std::find_if(spells.begin(), spells.end(), predicate);
    return (it == spells.end() ? nullptr : (*it).first);
}

std::unordered_map<AbstractMagic*, int>::iterator SpellsDeck::begin() {
    return spells.begin();
}

std::unordered_map<AbstractMagic*, int>::iterator SpellsDeck::end() {
    return spells.end();
}

int SpellsDeck::getCooldown(std::string name) noexcept {
    auto predicate = [&name](auto pair) {
        return pair.first->getName() == name;
    };
    auto it = std::find_if(spells.begin(), spells.end(), predicate);
    return (it == spells.end() ? 100 : (*it).second);
}

int SpellsDeck::getCooldown(AbstractMagic* spell) noexcept {
    return (this->contains(spell) ? spells[spell] : 100);
}

void cast(AbstractMagic* spell, AbstractPlayer* lhs, AbstractPlayer* rhs) {
    spell->action(lhs, rhs);
    lhs->changeStat(StatType::MANA, -manaCost);
    this->spellCasted(this);
}