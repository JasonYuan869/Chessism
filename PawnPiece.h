#ifndef PAWNPIECE_H
#define PAWNPIECE_H

#include <vector>
#include "Move.h"
#include "BoardState.h"


class PawnPiece : public Piece {
    void enPassant(BoardState &board, std::vector<Move> &moves) const;

    void addToMoveList(int, int, Piece *, std::vector<Move> &) const;

    bool enPassantAttacking(int target_x, int target_y, BoardState &board) const;

public:
    static double value;
    static PieceType type;

    PawnPiece(int, int, bool);

    std::vector<Move> getPieceMoves(BoardState &board) const override;

    bool isAttacking(int x, int y, BoardState &board) const override;

    double getValue() override;

    PieceType getType() override;

};

#endif
