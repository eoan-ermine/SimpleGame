#include "Inventory.h"

Inventory::Inventory() {
}

Inventory::~Inventory() {
}


void Inventory::addItem(Item* item) noexcept {
    inventory.insert({hash(item), item});
}

void Inventory::deleteItem(Item* item) noexcept {
    inventory.erase(hash(item));
}

void Inventory::reset() noexcept {
    inventory.clear();
}

std::size_t Inventory::size() const noexcept {
    return inventory.size();
}

bool Inventory::contains(Item* key) const noexcept {
    return inventory.find(hash(key)) != inventory.end();
}

const std::unordered_map<std::size_t, Item*>& Inventory::getItems() const noexcept {
    return inventory;
}

Item* Inventory::getItem(size_t hash) const {
    if(auto it = inventory.find(hash); it != inventory.end()) {
        return (*it).second;
    } else {
        throw std::out_of_range("Can't found item with provided hash");
    }
}

Item* Inventory::operator[](size_t hash) const noexcept {
    if(auto it = inventory.find(hash); it != inventory.end()) {
        return (*it).second;
    } else {
        return nullptr;
    }
}
