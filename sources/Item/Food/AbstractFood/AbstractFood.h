#pragma once

#include "../../Item.h"

class AbstractPlayer;

class AbstractFood: public Item {
public:
    int value;
public:
    AbstractFood(int value);
    AbstractFood(std::string name, std::string description, int value);
    ~AbstractFood();

    void setValue(int newValue);
    int getValue();

    virtual void use(AbstractPlayer* lhs, AbstractPlayer* rhs) override;
};
