#pragma once

#include <vector>
#include <algorithm>

#include "../../Maze/MazeSystem/AbstractMaze/AbstractMaze.h"
#include "../../Maze/RoomSystem/AbstractRoom/AbstractRoom.h"
#include "../../Item/Inventory/Inventory.h"
#include "../../Effect/AbstractEffect.h"
#include "../../Effect/StarveEffect/StarveEffect.h"

#include "../../Item/Equipment/AbstractWeapon/AbstractWeapon.h"
#include "../../Item/Equipment/AbstractArmor/AbstractArmor.h"
#include "../../GameWindow/Game/GameObject/GameObject.h"

class AbstractPlayer: public GameObject {
private:
    AbstractMaze* currentMaze = nullptr;
    AbstractRoom* currentRoom = nullptr;

    struct {
        float health=100, hunger=100, maxHealth=100, maxHunger=100;
        int accuracy=10, evasion=10, strength=10, experience=0, level=1;
    } stats;

    struct {
        struct {
            AbstractWeapon *first;
        } weapon;
        struct {
            AbstractArmor *head, *body, *legs, *boots;
        } armor;
    } wearedEquipment;

    std::vector<AbstractEffect*> effects;
    Inventory inventory;
public:
    AbstractPlayer();
    AbstractPlayer(float health, float hunger);
    virtual ~AbstractPlayer();

    void setMaze(AbstractMaze* newMaze) noexcept;
    AbstractMaze* getMaze() const;

    void setRoom(AbstractRoom* newRoom) noexcept;
    AbstractRoom* getRoom() const;

    virtual void tick() noexcept;

    bool setStat(StatType stat, int value) noexcept;
    bool setStat(StatType stat, float value) noexcept;

    bool changeStat(StatType stat, int value) noexcept;
    bool changeStat(StatType stat, float value) noexcept;

    float getStat(StatType stat) const noexcept;

    bool wearEquipment(AbstractArmor* armor);
    bool wearEquipment(AbstractWeapon* weapon);
    void unwearEquipment(EquipmentType equipmentType, ArmorType armorType);

    Inventory* getInventory() noexcept;
    bool dropItem(Item* item) noexcept;
    bool getItem(Item* item) noexcept;

    std::vector<AbstractEffect*>& getEffects() noexcept;
    void addEffect(AbstractEffect* effect) noexcept;
    void deleteEffect(AbstractEffect* effect) noexcept;
};
