#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include "BoardState.h"

using namespace std;

class Move {
    pair<int, int> to;
    pair<int, int> from;
    char promotion;
    public: 
        Move(int to_x,int to_y, int from_x,int from_y, char promotion = '-');
        ~Move();
};

#endif
