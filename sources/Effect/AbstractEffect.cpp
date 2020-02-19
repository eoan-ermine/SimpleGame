#include "AbstractEffect.h"

#include "../Player/AbstractPlayer/AbstractPlayer.h"

AbstractEffect::AbstractEffect(int duration): duration(duration) {
}

AbstractEffect::~AbstractEffect() {
}

int AbstractEffect::getDuration() {
    return this->duration;
}
