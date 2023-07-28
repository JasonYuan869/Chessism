#include "RookPiece.h"
using namespace std;

double RookPiece::value = 5;

RookPiece::RookPiece(int x, int y,bool isWhite) : Piece{x,y,isWhite,true} {

}

RookPiece::~RookPiece() {

}

vector<Move> RookPiece::getPieceMoves(BoardState& board) const {
    vector<Move> moves;
    int x = position_x;
    int y = position_y;
    int directions[2][2] = {{0,1},{1,0}};

    for (auto& direction : directions){

        int tempx = x + direction[0];
        int tempy = y + direction[1];
        while (withinBounds(tempx, tempy)){
            if (board.board[tempy][tempx] != nullptr ) {
                if  (board.board[tempy][tempx]->isWhite != isWhite){
                    moves.push_back(Move{tempx,tempy,x,y});
                } 
                break;
            } else {
                moves.push_back(Move{tempx,tempy,x,y});
                tempx += direction[0];
                tempy += direction[1];
            }
        } 

        tempx = x - direction[0];
        tempy = y - direction[1];
        while (withinBounds(tempx, tempy)){
            if (board.board[tempy][tempx] != nullptr ) {
                if  (board.board[tempy][tempx]->isWhite != isWhite){
                    moves.push_back(Move{tempx,tempy,x,y});
                } 
                break;
            } else {
                moves.push_back(Move{tempx,tempy,x,y});
                tempx -= direction[0];
                tempy -= direction[1];
            }
        } 
    }
    return moves;
}

bool RookPiece::isAttacking(int x, int y, BoardState& board) const {
    int directions[2][2] = {{0,1},{1,0}};


    for (auto& direction : directions){

        int tempx = position_x + direction[0];
        int tempy = position_y + direction[1];
        while (withinBounds(tempx, tempy)){
            if (board.board[tempy][tempx] != nullptr ) {
                if  (board.board[tempy][tempx]->isWhite != isWhite){
                    if (tempx == x && tempy == y){
                        return true;
                    }                
                } 
                break;
            } else {
                if (tempx == x && tempy == y){
                    return true;
                }
                tempx += direction[0];
                tempy += direction[1];
            }
        } 

        tempx = position_x - direction[0];
        tempy = position_y - direction[1];
        while (withinBounds(tempx, tempy)){
            if (board.board[tempy][tempx] != nullptr ) {
                if  (board.board[tempy][tempx]->isWhite != isWhite){
                    if (tempx == x && tempy == y){
                        return true;
                    }                
                } 
                break;
            } else {
                if (tempx == x && tempy == y){
                    return true;
                }
                tempx -= direction[0];
                tempy -= direction[1];
            }
        } 
    }
    return false;
}

double RookPiece::getValue() {
    return value;
}
