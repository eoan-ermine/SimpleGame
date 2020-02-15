#pragma once

#include "../AbstractPlayer/AbstractPlayer.h"

#include "../WarriorPlayer/WarriorPlayer.h"
#include "../MagePlayer/MagePlayer.h"
#include "../RoguePlayer/RoguePlayer.h"


enum PlayerType { MAGE, ROGUE, WARRIOR };

class PlayerFactory {
public:
    PlayerFactory();
    ~PlayerFactory();

    AbstractPlayer* createPlayer(PlayerType type);
};
