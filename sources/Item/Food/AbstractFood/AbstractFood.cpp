#include "AbstractFood.h"

#include "../../../Utility/Utility.h"
#include "../../../Player/AbstractPlayer/AbstractPlayer.h"

AbstractFood::AbstractFood(int value): Item("Default name", "Default description"), value(value) {}

AbstractFood::AbstractFood(std::string name, std::string description, int value): Item("Default name", "Default description"), value(value) {}

AbstractFood::~AbstractFood() {
}

void AbstractFood::setValue(int newValue) {
    this->value = newValue;
}

int AbstractFood::getValue() {
    return this->value;
}

void AbstractFood::use(AbstractPlayer* lhs, AbstractPlayer* rhs) {
    rhs->changeStat(StatType::HUNGER, value);
}
