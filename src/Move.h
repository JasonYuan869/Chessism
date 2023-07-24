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
    // If the move is a capture, then to2 == from2 == capturedOrMovedPiece->getPos()
    // If the move is a castle, then to2 == from2 is the rook's move and capturedOrMovedPiece is the rook
    // Otherwise, capturedOrMovedPiece is nullptr
    pair<int, int> to2;
    pair<int, int> from2;
    Piece* capturedOrMovedPiece;

    pair<int, int> getTo();

    pair<int, int> getFrom();

    Move(); // default
    Move(pair<int, int> to, pair<int, int> from, char promotion = '-');

    Move(int to_x, int to_y, int from_x, int from_y, char promotion = '-');

    Move(pair<int, int> to, pair<int, int> to2, pair<int, int> from, pair<int, int> from2, Piece* capturedOrMovedPiece);

    // Does not delete lastMove or capturedPiece as they are not owned by this object
    ~Move();

    // Delete all the lastMoves recursively, used when deleting the BoardState
    void freeLastMoves();
};

#endif
