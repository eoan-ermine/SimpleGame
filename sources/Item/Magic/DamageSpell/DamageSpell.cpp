#include "DamageSpell.h"

#include "../../../Player/AbstractPlayer/AbstractPlayer.h"

DamageSpell::DamageSpell(): AbstractMagic("Damage spell", "Spell damage something or somebody", 10, 5) { }

DamageSpell::~DamageSpell() { }

void DamageSpell::action(AbstractPlayer* lhs, AbstractPlayer* rhs) {
    rhs->changeStat(StatType::HEALTH, -10.0f);
}
