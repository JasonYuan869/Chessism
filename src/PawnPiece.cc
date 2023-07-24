#include "PawnPiece.h"


PawnPiece::PawnPiece(int x, int y,bool isWhite) : Piece{x,y,isWhite} {

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
        addToMoveList(x,new_y,moves);
        if ((isWhite && y == 1) || (!isWhite && y == 6)){
            int doubleMove = direction * 2;
            if (withinBounds(x,y + doubleMove) && board.board[y+doubleMove][x] == nullptr){
                addToMoveList(x,y+doubleMove,moves);
            }
        }
    }
    int new_x = x+1;

    if (withinBounds(new_x,new_y) && board.board[new_y][new_x] != nullptr && (board.board[new_y][new_x]->isWhite != isWhite) ){
        addToMoveList(new_x,new_y,moves);
    }

    new_x = x-1;
    if (withinBounds(new_x,new_y) && board.board[new_y][new_x] != nullptr && (board.board[new_y][new_x]->isWhite != isWhite) ){
        addToMoveList(new_x,new_y,moves);
    }
    
    enPassant(board,moves);
    return moves;

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


void PawnPiece::enPassant(BoardState& board, vector<Move>& moves){
    int x = position_x;
    int y = position_y;
    int lastxStart = board.lastMove.getFrom().first;
    int lastyStart = board.lastMove.getFrom().second;

    int lastxEnd = board.lastMove.getTo().first;
    int lastyEnd = board.lastMove.getTo().second;
    if (y == lastyEnd && abs(lastxEnd - x) == 1
        && board.board[y][lastxEnd] != nullptr 
        && board.board[y][lastxEnd]->getValue() == 1.0 
        && abs(lastyEnd - lastyStart) == 2
    ) {
        moves.push_back(Move{lastxEnd,(lastyEnd + lastyStart)/2,x,y,lastxEnd,lastxStart,0,0,2});
    }
    

}

void PawnPiece::addToMoveList(int new_x, int new_y,vector<Move>& moves) {
        int x = position_x;
        int y = position_y;
        char blackPromotions[4] = {'q','r','b','k'};
        char whitePromotions[4] = {'Q','R','B','K'};
        if (isWhite && y == 7){
            for (auto promotion : whitePromotions){
                moves.push_back(Move{new_x,new_y,x,y,promotion});
            }
        } else if (!isWhite && y == 0){
            for (auto promotion : blackPromotions){
                moves.push_back(Move{new_x,new_y,x,y,promotion});
            }
        } else {
            moves.push_back(Move{new_x,new_y,x,y});
        }
        return;
    }