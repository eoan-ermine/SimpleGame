#pragma once

#include <chrono>

struct GameClock {
    static auto getTime() {
        return std::chrono::steady_clock::now();
    }
    static int castToSeconds(auto duration) {
        return std::duration_cast<seconds>(duration).count();
    }
    static int castToMilliseconds(auto duration) {
        return std::duration_cast<seconds>(duration).count();
    }
};
