#ifndef BOARDSTATE_H
#define BOARDSTATE_H 

#include <vector>
#include "Move.h"
#include "KingPiece.h"
#include "Piece.h"

using namespace std;

class BoardState {
    public: 
    Piece* board[8][8]; 
    vector<Piece*> whitePieces;
    vector<Piece*> blackPieces; 
    KingPiece* whiteKing;
    KingPiece* blackKing;
    Move lastMove;
    vector<Move> validMoves;
        BoardState();
        ~BoardState();
        bool getCheckmate(bool white);
        bool getCheck(bool white, int x, int y);
        void updateValidMoves(bool white);
        bool movePiece(Move move);
};

#endif 
