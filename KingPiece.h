#ifndef KINGPIECE_H
#define KINGPIECE_H

#include <vector>
#include "Move.h"
#include "Piece.h"

class Move;

class BoardState;

class KingPiece : public Piece {
public:
    static double value;
    static PieceType type;
    bool checked;

    KingPiece(int, int, bool);

    std::vector<Move> getPieceMoves(BoardState &board) const override;

    bool isAttacking(int x, int y, BoardState &board) const override;

    double getValue() override;

    PieceType getType() override;
};

#endif
