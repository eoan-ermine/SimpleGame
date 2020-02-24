#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>

#include "../../Maze/MazeSystem/AbstractMaze/AbstractMaze.h"
#include "../../Maze/RoomSystem/AbstractRoom/AbstractRoom.h"
#include "../../Item/Inventory/Inventory.h"
#include "../../Effect/AbstractEffect.h"
#include "../../Effect/StarveEffect/StarveEffect.h"

#include "../../Item/Equipment/AbstractWeapon/AbstractWeapon.h"
#include "../../Item/Equipment/AbstractArmor/AbstractArmor.h"
#include "../../GameWindow/Game/GameObject/GameObject.h"
#include "../../Item/Magic/AbstractMagic/AbstractMagic.h"
#include "../../Item/SpellsDeck/SpellsDeck.h"
#include "../../Item/Food/AbstractEffectPotion/AbstractEffectPotion.h"

class AbstractPlayer: public GameObject {
private:
    AbstractMaze* currentMaze = nullptr;
    AbstractRoom* currentRoom = nullptr;

    struct {
        float health=100, hunger=100, maxHealth=100, maxHunger=100;
        int accuracy=10, evasion=10, strength=10, experience=0, level=1,
            maxMana = 100, mana = 100;
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
    SpellsDeck spells;
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

    AbstractWeapon* getWeapon(WeaponType type);
    AbstractArmor* getArmor(ArmorType type);

    Inventory* getInventory() noexcept;
    bool dropItem(Item* item) noexcept;
    bool getItem(Item* item) noexcept;
    bool giveItem(Item* item, AbstractPlayer* rhs);

    bool throwPotion(AbstractEffectPotion* potion, AbstractPlayer* victim);

    std::vector<AbstractEffect*>& getEffects() noexcept;
    void addEffect(AbstractEffect* effect) noexcept;
    void deleteEffect(AbstractEffect* effect) noexcept;

    SpellsDeck& getSpells() noexcept;
    bool canCast(AbstractMagic* spell) noexcept;
    void castSpell(std::string spellName, AbstractPlayer* victim) noexcept;
    void castSpell(AbstractMagic* spell, AbstractPlayer* victim) noexcept;
};
