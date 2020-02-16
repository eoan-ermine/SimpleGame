#include "PlayerFactory.h"

PlayerFactory::PlayerFactory() {
}

PlayerFactory::~PlayerFactory() {
}


AbstractPlayer* PlayerFactory::createPlayer(PlayerType type) {
    switch(type) {
    case PlayerType::WARRIOR:
        return new WarriorPlayer();
    case PlayerType::MAGE:
        return new MagePlayer();
    case PlayerType::ROGUE:
        return new RoguePlayer();
    default:
        return new AbstractPlayer();
    }
}
