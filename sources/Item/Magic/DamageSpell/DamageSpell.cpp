#include "DamageSpell.h"

#include "../../../Player/AbstractPlayer/AbstractPlayer.h"

DamageSpell::DamageSpell(): AbstractMagic("Damage spell", "Spell damage something or somebody", 10, 100) { }

DamageSpell::~DamageSpell() { }

void DamageSpell::action(AbstractPlayer* lhs, AbstractPlayer* rhs) {
    lhs->changeStat(StatType::HEALTH, -10);
}
