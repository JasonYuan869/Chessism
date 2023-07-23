#include "KingPiece.h"

KingPiece::KingPiece() {

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
