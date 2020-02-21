#include "GameWindow/GameWindow.h"
#include "Player/Monster/AbstractMonster.h"

int main() {
    GameWindow window;
    window.show();

    window.getGame()->changePlayer(new AbstractMonster());

    return 0;
}
