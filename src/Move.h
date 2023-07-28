#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include "BoardState.h"
#include "Piece.h"

class Move {
public:
    char promotion;
    std::pair<int, int> to;
    std::pair<int, int> from;
    

    //to2 and from2 are only used for castling, otherwise they are (-1,-1).
    std::pair<int, int> to2;
    std::pair<int, int> from2;
    Piece* capturedOrMovedPiece;

    std::pair<int, int> getTo();

    std::pair<int, int> getFrom();

    Move(); // default, we need for computerPlayer4

    //move with no capture
    Move(std::pair<int, int> to, std::pair<int, int> from, char promotion = '-');
    
    //move with a capture
    Move(std::pair<int, int> to, std::pair<int, int> from, Piece* capturedOrMovedPiece, char promotion = '-');
    
    //castling
    Move(std::pair<int, int> to, std::pair<int, int> to2, std::pair<int, int> from, std::pair<int, int> from2, Piece* capturedOrMovedPiece);

    // Does not delete lastMove or capturedPiece as they are not owned by this object
    ~Move();
    bool Move::operator==(Move& other);
};

#endif
