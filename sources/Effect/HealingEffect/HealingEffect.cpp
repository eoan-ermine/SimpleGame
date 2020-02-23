#include "BurningEffect.h"

#include "../../Player/AbstractPlayer/AbstractPlayer.h"

HealingEffect::HealingEffect(int duration): AbstractEffect("Healing effect", "Healing effect description", duration) {
}

HealingEffect::~HealingEffect() {
}

void HealingEffect::action(AbstractPlayer* ply) {
    AbstractEffect::action(ply);
    ply->changeStat(StatType::HEALTH, 2.5f);
}