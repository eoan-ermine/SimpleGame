#pragma once

#include "../../Utility/Utility.h"
#include "../Item.h"

#include <unordered_map>

class Inventory {
private:
    MyHash<Item> hash;
    std::unordered_map<std::size_t, Item*> inventory;
public:
    Inventory();
    ~Inventory();

    void addItem(Item* item) noexcept;
    void deleteItem(Item* item) noexcept;
    void reset() noexcept;

    std::size_t size() noexcept;
};
