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

namespace Piece {
    Piece* makePiece(char piece, int x, int y) {
        switch piece {
            case 'P':
                return new PawnPiece(x, y, true);
            case 'p':
                return new PawnPiece(x, y, false);
            case 'R':
                return new RookPiece(x, y, true);
            case 'r':
                return new RookPiece(x, y, false);
            case 'N':
                return new KnightPiece(x, y, true);
            case 'n':
                return new KnightPiece(x, y, false);
            case 'B':
                return new BishopPiece(x, y, true);
            case 'b':
                return new BishopPiece(x, y, false);
            case 'Q':
                return new QueenPiece(x, y, true);
            case 'q':
                return new QueenPiece(x, y, false);
            case 'K':
                return new KingPiece(x, y, true);
            case 'k':
                return new KingPiece(x, y, false);
        }
    }
}

#endif
