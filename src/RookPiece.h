#ifndef ROOKPIECE_H
#define ROOKPIECE_H

#include <vector>
#include "Move.h"
#include "BoardState.h"

class RookPiece : public Piece {
public:
    static double value;

    RookPiece(int,int,bool);

    ~RookPiece() override;

    std::vector<Move> getPieceMoves(BoardState &board) const override;

    bool isAttacking(int x, int y, BoardState &board) const override;

    double getValue() override;

};

#endif
