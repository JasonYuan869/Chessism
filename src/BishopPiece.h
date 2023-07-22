#ifndef BISHOPPIECE_H
#define BISHOPPIECE_H

#include <vector>
#include "Move.h"
#include "BoardState.h"

class BishopPiece : public Piece {
    public: 
        BishopPiece();
        ~BishopPiece();
        vector<Move> getPieceMoves(BoardState& board) override;
        bool isAttacking(int x, int y, BoardState& board) override;
};

#endif
