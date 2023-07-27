#ifndef KINGPIECE_H
#define KINGPIECE_H

#include <vector>
#include "Move.h"
#include "BoardState.h"
#include "Piece.h"

class Move;
class BoardState;

class KingPiece : public Piece {
public:
    static double value;
    bool checked;

    KingPiece(int,int,bool);

    ~KingPiece();

    std::vector<Move> getPieceMoves(BoardState &board) const override;

    bool isAttacking(int x, int y, BoardState &board) const override;

    double getValue() override;
};

#endif
