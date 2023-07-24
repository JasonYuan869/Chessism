#include "KingPiece.h"
#include "RookPiece.h"
double KingPiece::value = 1000;



KingPiece::KingPiece(int x, int y,bool isWhite) : Piece{x,y,isWhite,true}, checked{false}{

}

KingPiece::~KingPiece() {

}

vector<Move> KingPiece::getPieceMoves(BoardState& board) {
    int directions[3]= {1,0,-1};
    vector<Move> moves;
    int x = position_x;
    int y = position_y;
    for (auto xdirection: directions){
        for (auto ydirection:directions){
            if (xdirection != 0 || ydirection != 0){
                int new_x = x + xdirection;
                int new_y = y + ydirection;
                if (withinBounds(new_x, new_y) && board.board[new_y][new_x] == nullptr || (board.board[new_y][new_x]->isWhite != isWhite)){
                    moves.push_back(Move{new_x,new_y,x,y});
                }
            }
        }
    }


    //castle right
    if (canCastle && board.board[y][7] != nullptr && board.board[y][7]->canCastle ){
        bool rowEmpty = true;
        for (int i = x+1;i<7;i++){
            if (board.board[y][i] != nullptr){
                rowEmpty = false;
                break;
            }
        }

        if (rowEmpty && !board.getAttacked(x+1,y,!isWhite) && !board.getAttacked(x+2,y,!isWhite)){
            moves.push_back(Move{x+2,y,x,y,7,y,x+1,y,1});
        }
    }
    //castle left
    if (canCastle && board.board[y][0] != nullptr && board.board[y][0]->canCastle ){
        bool rowEmpty = true;
        for (int i = x-1;i>=0;i--){
            if (board.board[y][i] != nullptr){
                rowEmpty = false;
                break;
            }
        }

        if (rowEmpty && !board.getAttacked(x-1,y,!isWhite) && !board.getAttacked(x-2,y,!isWhite)){
            moves.push_back(Move{x-2,y,x,y,0,y,x-1,y,1});
        }
    }

    return moves;
}

bool KingPiece::isAttacking(int x, int y, BoardState& board) {
    
    int directions[3]= {1,0,-1};
    
    for (auto xdirection: directions){
        for (auto ydirection:directions){
            if (xdirection != 0 || ydirection != 0){
                int new_x = position_x + xdirection;
                int new_y = position_y + ydirection;
                if (new_x == x && new_y == y){
                    return true;
                }
            }
        }
    }
    return false;
}
