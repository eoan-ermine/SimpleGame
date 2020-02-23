#include "AbstractEffect.h"

#include "../Player/AbstractPlayer/AbstractPlayer.h"

AbstractEffect::AbstractEffect(std::string name, std::string description, int duration): AbstractEffect(duration) {
	this->name = name;
	this->description = description;
}

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

std::string_view AbstractEffect::getName() const noexcept {
	return this->name;
}

std::string_view AbstractEffect::getDescription() const noexcept {
	return this->description;
}

void AbstractEffect::setName(std::string name) noexcept {
	this->name = name;
}

void AbstractEffect::setDescription(std::string description) noexcept {
	this->description = description;
}

void AbstractEffect::setDuration(int newDuration) noexcept {
	this->duration = newDuration;
}

void AbstractEffect::setRemains(int newRemains) noexcept {
	this->remains = newRemains;
}

void AbstractEffect::setPermanent(bool newPermanent) noexcept {
	this->permanent = newPermanent;
}