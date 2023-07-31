#ifndef BISHOPPIECE_H
#define BISHOPPIECE_H

#include <vector>
#include "../Move.h"
#include "../BoardState.h"

class BishopPiece : public Piece {
public:
    static double value;
    static PieceType type;

    BishopPiece(int, int, bool);

    std::vector<Move> getPieceMoves(BoardState &board) const override;

    bool isAttacking(int x, int y, BoardState &board) const override;

    double getValue() override;

    PieceType getType() override;
};

#endif
