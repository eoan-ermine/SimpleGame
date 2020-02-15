#include "AbstractEffect.h"

#include "../Player/AbstractPlayer/AbstractPlayer.h"

AbstractEffect::AbstractEffect(int duration): duration(duration), remain(duration) {
}

AbstractEffect::~AbstractEffect() {
}
