#pragma once

#include <string>
#include <string_view>

#include "../Utility/Utility.h"
#include "../GameWindow/Game/GameObject/GameObject.h"

class AbstractPlayer;

class Item: public GameObject {
private:
    std::string name;
    std::string description;
    ItemType type;
public:
    Item();
    Item(std::string name, std::string description);
    Item(std::string name, std::string description, ItemType type);
    virtual ~Item();

    void setName(std::string newName);
    void setDescription(std::string newDescription);

    virtual void use(AbstractPlayer* lhs, AbstractPlayer* rhs);

    std::string_view getName();
    std::string_view getDescription();
};
