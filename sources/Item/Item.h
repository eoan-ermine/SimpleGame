#pragma once

#include <string>
#include <string_view>

enum ItemType { ITEM, EQUIPMENT };

class Item {
    std::string name;
    std::string description;
    ItemType type;
public:
    Item(std::string name, std::string description, ItemType type);
    ~Item();

    void setName(std::string newName);
    void setDescription(std::string newDescription);

    std::string_view getName();
    std::string_view getDescription();
};
