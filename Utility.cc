#include "Utility.h"

std::random_device Utility::rd;
std::mt19937 Utility::gen(rd());

int Utility::randomInt(int min, int max) {
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

bool Utility::withinBounds(int x,int y){
     return (x >=0 && x < 8 && y >= 0 && y < 8);
}

bool Utility::doubleEquality(double a, double b, double epsilon) {
    return std::fabs(a - b) < epsilon;
}
