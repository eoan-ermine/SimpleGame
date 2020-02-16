#include "Item.h"

Item::Item(): name("Default name"), description("Default description"), type(ItemType::ITEM) {}

Item::Item(std::string name, std::string description): name(std::move(name)), description(std::move(description)), type(ItemType::ITEM) { }

Item::Item(std::string name, std::string description, ItemType type): name(std::move(name)), description(std::move(description)), type(type) { }

Item::~Item() {
}

void Item::setName(std::string newName) {
    this->name = std::move(newName);
}

void Item::setDescription(std::string newDescription) {
    this->description = std::move(newDescription);
}

std::string_view Item::getName() {
    return this->name;
}

std::string_view Item::getDescription() {
    return this->description;
}
