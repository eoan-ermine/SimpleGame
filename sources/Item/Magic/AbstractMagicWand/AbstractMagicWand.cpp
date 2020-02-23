#include "AbstractMagicWand.h"

#include "../../../Player/AbstractPlayer/AbstractPlayer.h"

AbstractMagicWand::AbstractMagicWand(AbstractMagic* newSpell): spell(newSpell) {
	this->magicWandInfo.maxCountOfUse = 10;
	this->magicWandInfo.countOfUse = 10;
}

~AbstractMagicWand::AbstractMagicWand(AbstractMagic* newSpell, int countOfUse, int maxCountOfUse): spell(newSpell) {
	this->magicWandInfo.maxCountOfUse = maxCountOfUse;
	this->magicWandInfo.countOfUse = countOfUse;
}
	
AbstractMagic* AbstractMagicWand::getMagic() {
	return this->spell;
}

void AbstractMagicWand::setMagic(AbstractMagic* newSpell) {
		this->spell = newSpell;
}

void AbstractMagicWand::use(AbstractPlayer* lhs, AbstractPlayer* rhs) {
	if(this->countOfUse != 0) {
		this->spell->use(lhs, rhs);
	}
}

int getCountOfUse() {
	return this->countOfUse;
}

int getMaxCountOfUse() {
	return this->maxCountOfUse;
}
	
void setCountOfUse(int countOfUse) {
	this->countOfUse = countOfUse;
}

void setMaxCountOfUse(int maxCountOfUse) {
	this->maxCountOfUse = maxCountOfUse;
}