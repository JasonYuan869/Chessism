#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "Move.h"
#include "BoardState.h"


class Piece {
    
    public: 
    int position_x;
    int position_y;
    bool isWhite;
    bool isAlive;
        bool withinBounds(int x,int y); //returns true if the position is inside the board
        virtual ~Piece()=0;
        virtual std::vector<Move> getPieceMoves(BoardState& board)=0;
        virtual bool isAttacking(int x, int y, BoardState& board)=0;
};

#endif
