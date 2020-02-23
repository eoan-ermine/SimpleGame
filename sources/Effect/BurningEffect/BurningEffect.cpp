#include "BurningEffect.h"

#include "../../Player/AbstractPlayer/AbstractPlayer.h"

BurningEffect::BurningEffect(int duration): AbstractEffect("Burning effect", "Burning effect description", duration) {
}

BurningEffect::~BurningEffect() {
}

void BurningEffect::action(AbstractPlayer* ply) {
    AbstractEffect::action(ply);
    ply->changeStat(StatType::HEALTH, -2.5f);
}