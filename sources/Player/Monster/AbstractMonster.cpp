#include "AbstractMonster.h"

AbstractMonster::AbstractMonster(): AbstractPlayer(100, 0) {
}

AbstractMonster::AbstractMonster(int health): AbstractPlayer(health, 0) {
}

AbstractMonster::~AbstractMonster() {
}
