#pragma once

#include "../../Utility/Utility.h"
#include "../Item.h"
#include "../../GameWindow/Game/GameObject/GameObject.h"

#include <unordered_map>

class Inventory: public GameObject {
private:
    MyHash<Item> hash;
    std::unordered_map<std::size_t, Item*> inventory;
public:
    Inventory();
    ~Inventory();

    const std::unordered_map<std::size_t, Item*>& getItems() const noexcept;

    void addItem(Item* item) noexcept;
    void deleteItem(Item* item) noexcept;
    void reset() noexcept;

    std::size_t size() const noexcept;
    bool contains(Item* key) const noexcept;

    Item* getItem(size_t hash) const;
    Item* operator[](size_t hash) const noexcept;
};
