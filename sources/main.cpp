#include "GameWindow/GameWindow.h"
#include "Player/AbstractMonster/AbstractMonster.h"

int main() {
    GameWindow window;
    window.show();

    window.getGame()->changePlayer(new AbstractMonster());

    return 0;
}
