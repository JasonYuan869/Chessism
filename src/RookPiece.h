#ifndef ROOKPIECE_H
#define ROOKPIECE_H

#include <vector>
#include "Move.h"
#include "BoardState.h"

class RookPiece : public Piece {
public:
    static double value;

    RookPiece();

    ~RookPiece();

    vector <Move> getPieceMoves(BoardState &board) override;

    bool isAttacking(int x, int y, BoardState &board) override;
};

#endif
