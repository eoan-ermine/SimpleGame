#include "Inventory.h"

Inventory::Inventory() {
}

Inventory::~Inventory() {
}

const std::vector<Item*>& Inventory::getItems() const noexcept {
    return this->items;
}

void Inventory::addItem(Item* item) noexcept {
    items.push_back(item);
}

void Inventory::deleteItem(Item* item) noexcept {
    if(auto it = std::find(items.begin(), items.end(), item); it != items.end()) {
        items.erase(it);
    }
}

void Inventory::reset() noexcept {
    items.clear();
}

std::size_t Inventory::size() const noexcept {
    return items.size();
}

bool Inventory::contains(std::string name) {
    auto predicate = [&name](Item* item) {
        return item->getName() == name;
    };
    if(auto it = std::find_if(items.begin(), items.end(), predicate); it != items.end()) {
        return true;
    }
    return false;
}

bool Inventory::contains(Item* key) const noexcept {
    if(auto it = std::find(items.begin(), items.end(), key); it != items.end()) {
        return true;
    }
    return false;
}

Item* Inventory::getItem(std::string name) const {
    auto predicate = [&name](Item* item) {
        return item->getName() == name;
    };
    if(auto it = std::find_if(items.begin(), items.end(), predicate); it != items.end()) {
        return *it;
    }
    throw std::runtime_error("Can't find spell with provided name");
}

Item* Inventory::operator[](std::string name) const noexcept {
    auto predicate = [&name](Item* item) {
        return item->getName() == name;
    };
    if(auto it = std::find_if(items.begin(), items.end(), predicate); it != items.end()) {
        return *it;
    }
    return nullptr;
}
