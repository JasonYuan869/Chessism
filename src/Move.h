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
    // If the move is a capture, then to2 == from2 == capturedOrMovedPiece->getPos()
    // If the move is a castle, then to2 == from2 is the rook's move and capturedOrMovedPiece is the rook
    // Otherwise, capturedOrMovedPiece is nullptr
    std::pair<int, int> to2;
    std::pair<int, int> from2;
    Piece* capturedOrMovedPiece;

    std::pair<int, int> getTo();

    std::pair<int, int> getFrom();

    Move(); // default
    Move(std::pair<int, int> to, std::pair<int, int> from, char promotion = '-');

    Move(int to_x, int to_y, int from_x, int from_y, char promotion = '-');

    Move(std::pair<int, int> to, std::pair<int, int> to2, std::pair<int, int> from, std::pair<int, int> from2, Piece* capturedOrMovedPiece);

    // Does not delete lastMove or capturedPiece as they are not owned by this object
    ~Move();
};

#endif
