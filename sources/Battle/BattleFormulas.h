#pragma once

#include "../Utility/RandomGenerator.h"

struct BattleFormulas {
    static bool hitSuccessful(int aAccuracy, int vDodge) {
        return RandomGenerator{0, aAccuracy}() >= RandomGenerator{0, vDodge}();
    }
    static int calculateDamage(int aMinHitValue, int aMaxHitValue, int vArmor) {
        RandomGenerator firstGenerator = RandomGenerator(aMinHitValue, aMaxHitValue);
        RandomGenerator secondGenerator = RandomGenerator(0, vArmor);

        int result = firstGenerator() - secondGenerator();
        return (result < 0 ? 0 : result);
    }
};
