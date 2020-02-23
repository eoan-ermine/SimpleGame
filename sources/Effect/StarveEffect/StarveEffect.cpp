#include "StarveEffect.h"

#include "../../Player/AbstractPlayer/AbstractPlayer.h"

StarveEffect::StarveEffect(int duration): AbstractEffect("Starve effect", "Starve effect description", duration) {
}

StarveEffect::~StarveEffect() {
}

void StarveEffect::action(AbstractPlayer* ply) {
    AbstractEffect::action(ply);
    ply->changeStat(StatType::HUNGER, -0.2f);
}
