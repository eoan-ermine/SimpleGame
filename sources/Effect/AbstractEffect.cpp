#include "AbstractEffect.h"

#include "../Player/AbstractPlayer/AbstractPlayer.h"

AbstractEffect::AbstractEffect(int duration): duration(duration), last(duration) {
    if(duration == 0) {
        permanent = true;
    }
}

AbstractEffect::~AbstractEffect() {
}

int AbstractEffect::getDuration() const noexcept {
    return this->duration;
}

int AbstractEffect::getRemains() const noexcept {
    return this->last;
}

bool AbstractEffect::isPermanent() const noexcept {
    return this->permanent;
}

void AbstractEffect::action(AbstractPlayer* ply) {
    if(not permanent) {
        last -= 1;
    }
}
