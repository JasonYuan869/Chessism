#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "Move.h"
#include "BoardState.h"

using namespace std;

class Piece {
    int position_x;
    int position_y;
    bool isWhite;
    bool isAlive;
    public: 
        virtual ~Piece()=0;
        virtual vector<Move> getPieceMoves(BoardState& board)=0;
        virtual bool isAttacking(int x, int y, BoardState& board)=0;
};

#endif
