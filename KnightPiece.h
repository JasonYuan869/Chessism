#ifndef KNIGHTPIECE_H
#define KNIGHTPIECE_H

#include <vector>
#include "Move.h"
#include "BoardState.h"

class KnightPiece : public Piece {
public:
    static double value;
    static PieceType type;

    KnightPiece(int, int, bool);

    std::vector<Move> getPieceMoves(BoardState& board) const override;

    bool isAttacking(int x, int y, BoardState& board) const override;

    double getValue() override;

    PieceType getType() override;
};

#endif