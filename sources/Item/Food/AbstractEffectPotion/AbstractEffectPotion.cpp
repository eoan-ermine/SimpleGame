#include "AbstractEffectPotion.h"

#include "../../../Player/AbstractPlayer/AbstractPlayer.h"
#include "../../../Effect/AbstractEffect.h"

AbstractEffectPotion::AbstractEffectPotion(AbstractEffect* effect): Item("Default potion name", "Default potion description", ItemType::ITEM) {
	this->effect = effect;	
}

AbstractEffectPotion(std::string name, std::string description, AbstractEffect* effect): Item(name, description, ItemType::ITEM) {
	this->effect = effect;	
}
	
void AbstractEffectPotion::setEffect(AbstractEffect* newEffect) {
	this->effect = newEffect;
}

AbstractEffect* AbstractEffectPotion::getEffect(AbstractEffect* newEffect) {
	return this->effect;
}
	
void AbstractEffectPotion::use(AbstractPlayer* lhs, AbstractPlayer* rhs) {
	rhs->addEffect(effect);
}