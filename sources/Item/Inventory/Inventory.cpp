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

std::size_t Inventory::size() noexcept {
    return inventory.size();
}

bool Inventory::contains(Item* key) const noexcept {
    return inventory.find(hash(key)) != inventory.end();
}
