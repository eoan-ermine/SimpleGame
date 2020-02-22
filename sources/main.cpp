#include "GameWindow/TextGameWindow/TextGameWindow.h"
#include "Player/AbstractMonster/AbstractMonster.h"

int main() {
    TextGameWindow window;
    window.show();

    window.getGame()->changePlayer(new AbstractMonster());

    return 0;
}
