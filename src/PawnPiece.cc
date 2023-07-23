#include "PawnPiece.h"

double PawnPiece::value = 1;

PawnPiece::PawnPiece() {

}

PawnPiece::~PawnPiece() {

}

vector<Move> PawnPiece::getPieceMoves(BoardState& board) { //TODO: add en passant, promotion
    
    vector<Move> moves;
    int x = position_x;
    int y = position_y;
    int direction = isWhite ? 1 : -1;
    int new_y = y + direction;
    if (withinBounds(x,new_y) && board.board[new_y][x] == nullptr){
        moves.push_back(Move{x,new_y,x,y});
        if ((isWhite && y == 1) || (!isWhite && y == 6)){
            int doubleMove = direction * 2;
            if (withinBounds(x,y+  doubleMove) && board.board[y+doubleMove][x] == nullptr){
                moves.push_back(Move{x,y+doubleMove,x,y});
            }
        }
    }
    int new_x = x+1;

    if (withinBounds(new_x,new_y) && board.board[new_y][new_x] != nullptr && (board.board[new_y][new_x]->isWhite != isWhite) ){
        moves.push_back(Move(new_x,new_y,x,y));
    }

    new_x = x-1;
    if (withinBounds(new_x,new_y) && board.board[new_y][new_x] != nullptr && (board.board[new_y][new_x]->isWhite != isWhite) ){
        moves.push_back(Move(new_x,new_y,x,y));
    }
   

}

bool PawnPiece::isAttacking(int x, int y, BoardState& board) {
    int direction = isWhite ? 1 : -1;
    int new_y = position_y + direction;
    int new_x = position_x+1;

    if (new_y == y && new_x == x){
        return true;
    }

    new_x = x-1;
    if (new_y == y && new_x == x){
        return true;
    }
    return false;
}
