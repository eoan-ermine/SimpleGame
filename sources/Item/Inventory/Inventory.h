#pragma once

#include "../../Utility/Utility.h"
#include "../Item.h"
#include "../../GameWindow/Game/GameObject/GameObject.h"

#include <stdexcept>
#include <algorithm>
#include <vector>

class Inventory: public GameObject {
private:
    std::vector<Item*> items;
public:
    Inventory();
    ~Inventory();

    const std::vector<Item*>& getItems() const noexcept;

    void addItem(Item* item) noexcept;
    void deleteItem(Item* item) noexcept;
    void reset() noexcept;

    std::size_t size() const noexcept;

    bool contains(std::string name);
    bool contains(Item* key) const noexcept;

    Item* getItem(std::string name) const;
    Item* operator[](std::string name) const noexcept;
};
