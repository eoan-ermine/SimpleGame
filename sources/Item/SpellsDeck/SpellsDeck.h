#pragma once

#include <algorithm>
#include <unordered_map>
#include <stdexcept>

#include "../Magic/AbstractMagic/AbstractMagic.h"

class SpellsDeck {
private:
    std::unordered_map<AbstractMagic*, int> spells;
public:
    SpellsDeck();
    ~SpellsDeck();

    std::unordered_map<AbstractMagic*, int>& getSpells() noexcept;
    void addSpell(AbstractMagic* spell) noexcept;
    void deleteSpell(AbstractMagic* spell) noexcept;
    void spellCasted(AbstractMagic* spell) noexcept;

    bool contains(AbstractMagic* key) const noexcept;
    bool contains(std::string name) const noexcept;

    AbstractMagic* getSpell(std::string name) noexcept;
    AbstractMagic* operator[](std::string name) noexcept;

    std::unordered_map<AbstractMagic*, int>::iterator begin();
    std::unordered_map<AbstractMagic*, int>::iterator end();

    int getCooldown(AbstractMagic* spell) noexcept;
    int getCooldown(std::string name) noexcept;
	
	void cast(AbstractMagic* spell, AbstractPlayer* lhs, AbstractPlayer* rhs);
};
