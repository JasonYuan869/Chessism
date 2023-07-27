#ifndef KINGPIECE_H
#define KINGPIECE_H

#include <vector>
#include "Move.h"
#include "BoardState.h"
#include "Piece.h"

class KingPiece : public Piece {
public:
    static double value;

    KingPiece(int,int,bool);

    ~KingPiece();

    std::vector<Move> getPieceMoves(BoardState &board) override;

    bool isAttacking(int x, int y, BoardState &board) override;

    bool checked;
};

#endif
