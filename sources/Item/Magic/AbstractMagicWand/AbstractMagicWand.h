#pragma once

#include "../AbstractMagic/AbstractMagic.h"
#include "../../Equipment/AbstractWeapon/AbstractWeapon.h"

class AbstractMagicWand: public AbstractWeapon {
private:
	AbstractMagic* spell;
	struct {
		int countOfUse, maxCountOfUse;
	} magicWandInfo;
public:
	AbstractMagicWand(AbstractMagic* newSpell);
	AbstractMagicWand(AbstractMagic* newSpell, int countOfUse, int maxCountOfUse);

	virtual ~AbstractMagicWand();
	
	AbstractMagic* getMagic();
	void setMagic(AbstractMagic* newSpell);
	
	int getCountOfUse();
	int getMaxCountOfUse();
	
	void setCountOfUse(int countOfUse);
	void setMaxCountOfUse(int maxCountOfUse);
	
	virtual void use(AbstractPlayer* lhs, AbstractPlayer* rhs) override;
}