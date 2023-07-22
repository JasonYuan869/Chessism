#ifndef KNIGHTPIECE_H
#define KNIGHTPIECE_H

#include <vector>
#include "Move.h"
#include "BoardState.h"

using namespace std;

class KnightPiece : public Piece {
    public: 
        KnightPiece();
        ~KnightPiece();
        vector<Move> getPieceMoves(BoardState& board);
        bool isAttacking(int x, int y, BoardState& board);
};

#endif
