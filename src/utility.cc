#include "utility.h"

std::random_device Utility::rd;
std::mt19937 Utility::gen(rd());

int Utility::randomInt(int min, int max) {
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}
