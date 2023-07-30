#ifndef CHESSISM_UTILITY_H
#define CHESSISM_UTILITY_H

#include <random>

class Utility {
    static std::random_device rd;
    static std::mt19937 gen;
public:
    // Returns a random integer between min and max, inclusive.
    static int randomInt(int min, int max);
    static bool withinBounds (int x,int y);
    
};

#endif //CHESSISM_UTILITY_H
