#pragma once

#include "../Item.h"
#include "../../Utility/Utility.h"

class AbstractEquipment: public Item {
private:
    EquipmentType equipmentType;
    struct {
        int maxHitPoints, hitPoints, mass;
    } commonInfo;
public:
    AbstractEquipment(EquipmentType equipmentType);
    AbstractEquipment(std::string name, std::string description, EquipmentType equipmentType);
    ~AbstractEquipment();

    void setHitPoints(int newHitPoints);
    void setMaxHitPoints(int newMaxHitPoints);
    void setMass(int newMass);

    EquipmentType getEquipmentType();

    int getHitPoints();
    int getMaxHitPoints();
    int getMass();
};
