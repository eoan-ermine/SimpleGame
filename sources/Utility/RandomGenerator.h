#pragma once

#include <random>

class RandomGenerator {
private:
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
public:
    RandomGenerator(int from, int to): gen(rd()), dis(from, to) {}
    int operator()() {
        return static_cast<int>(dis(gen));
    }
};
