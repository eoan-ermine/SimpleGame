#include "AbstractMagicWand.h"

#include "../../../Player/AbstractPlayer/AbstractPlayer.h"

AbstractMagicWand::AbstractMagicWand(AbstractMagic* newSpell): AbstractWeapon(WeaponType::FIRST) {
    this->spell = newSpell;
    this->magicWandInfo.maxCountOfUse = 10;
    this->magicWandInfo.countOfUse = 10;
}

AbstractMagicWand::AbstractMagicWand(std::string name, std::string description, AbstractMagic* newSpell, int countOfUse, int maxCountOfUse): AbstractWeapon(name, description, WeaponType::FIRST) {
    this->spell = newSpell;
    this->magicWandInfo.maxCountOfUse = maxCountOfUse;
    this->magicWandInfo.countOfUse = countOfUse;
}

AbstractMagicWand::~AbstractMagicWand() { }


AbstractMagic* AbstractMagicWand::getMagic() {
    return this->spell;
}

void AbstractMagicWand::setMagic(AbstractMagic* newSpell) {
    this->spell = newSpell;
}

void AbstractMagicWand::use(AbstractPlayer* lhs, AbstractPlayer* rhs) {
    if(this->magicWandInfo.countOfUse != 0) {
        this->spell->use(lhs, rhs);
    }
}

int AbstractMagicWand::getCountOfUse() {
    return this->magicWandInfo.countOfUse;
}

int AbstractMagicWand::getMaxCountOfUse() {
    return this->magicWandInfo.maxCountOfUse;
}

void AbstractMagicWand::setCountOfUse(int countOfUse) {
    this->magicWandInfo.countOfUse = countOfUse;
}

void AbstractMagicWand::setMaxCountOfUse(int maxCountOfUse) {
    this->magicWandInfo.maxCountOfUse = maxCountOfUse;
}
