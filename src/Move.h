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
        int nextMove; // 0 means no next move, 1 means move, 2 means delete
        pair<int,int> to2;
        pair<int,int> from2;
        pair<int, int> getTo();
        pair<int,int> getFrom();
        Move(); // default
        Move(pair<int, int> to, pair<int, int> from, char promotion = '-');
        Move(int to_x,int to_y, int from_x,int from_y, char promotion = '-');
        Move(int to_x,int to_y, int from_x,int from_y,int to_x2,int to_y2, int from_x2,int from_y2,int nextMove);
        ~Move();
        // copy assignment operator;
};

#endif
