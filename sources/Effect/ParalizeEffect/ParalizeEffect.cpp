#include "ParalizeEffect.h"

#include "../../Player/AbstractPlayer/AbstractPlayer.h"

ParalizeEffect::ParalizeEffect(int duration): AbstractEffect("Paralize effect", "Paralize effect description", duration) {
}

ParalizeEffect::~ParalizeEffect() {
}

void ParalizeEffect::preAction(AbstractPlayer* ply) {
    ply->setState(StateType::WALK, false);
    ply->setState(StateType::RUN, false);
    ply->setState(StateType::ATTACK, false);
}

void ParalizeEffect::afterAction(AbstractPlayer* ply) {
    ply->setState(StateType::WALK, true);
    ply->setState(StateType::RUN, true);
    ply->setState(StateType::ATTACK, true);
}
