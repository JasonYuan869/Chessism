#ifndef KNIGHTPIECE_H
#define KNIGHTPIECE_H

#include <vector>
#include "Move.h"
#include "BoardState.h"

class KnightPiece : public Piece {
public:
    static double value;

    KnightPiece(int,int,bool);

    ~KnightPiece() override;

    std::vector <Move> getPieceMoves(BoardState &board) const override;

    bool isAttacking(int x, int y, BoardState &board) const override;

    double getValue() override;
};

#endif
