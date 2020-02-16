#pragma once

#include <vector>

#include "../../Maze/MazeSystem/Maze/Maze.h"
#include "../../Maze/RoomSystem/AbstractRoom/AbstractRoom.h"
#include "../../Item/Inventory/Inventory.h"
#include "../../Effect/AbstractEffect.h"
#include "../../Effect/StarveEffect/StarveEffect.h"
#include "../../Item/Equipment/AbstractEquipment.h"

class AbstractPlayer {
private:
    Maze* currentMaze = nullptr;
    AbstractRoom* currentRoom = nullptr;

    struct {
        float health, armor, hunger;
        int accuracy, evasion, strength, experience, level;
    } stats;

    struct {
        struct {
            AbstractEquipment *first;
        } weapon;
        struct {
            AbstractEquipment *head, *body, *legs, *boots;
        } armor;
    } wearedEquipment;

    std::vector<AbstractEffect*> effects;
    Inventory inventory;
public:
    AbstractPlayer();
    AbstractPlayer(float health, float hunger);
    ~AbstractPlayer();

    void setMaze(Maze* newMaze) noexcept;
    Maze* getMaze() const;

    void setRoom(AbstractRoom* newRoom) noexcept;
    AbstractRoom* getRoom() const;

    void tick() noexcept;

    bool setStat(StatType stat, int value) noexcept;
    bool setStat(StatType stat, float value) noexcept;

    bool changeStat(StatType stat, int value) noexcept;
    bool changeStat(StatType stat, float value) noexcept;

    float getStat(StatType stat) const noexcept;

    bool wearEquipment(AbstractEquipment* equipment);
    void unwearEquipment(EquipmentType equipmentType, ArmorType armorType);

    Inventory* getInventory() noexcept;
};
