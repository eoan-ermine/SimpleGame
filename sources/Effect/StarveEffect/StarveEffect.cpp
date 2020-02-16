#include "StarveEffect.h"

#include "../../Player/AbstractPlayer/AbstractPlayer.h"

StarveEffect::StarveEffect(int duration): AbstractEffect(duration) {
}

StarveEffect::~StarveEffect() {
}


void StarveEffect::action(AbstractPlayer* ply) {
    ply->changeStat(StatType::HUNGER, -0.2f);
}
