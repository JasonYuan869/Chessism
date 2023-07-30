
#include "PawnPiece.h"
using namespace std;

double PawnPiece::value = 1;

PawnPiece::PawnPiece(int x, int y,bool isWhite) : Piece{x,y,isWhite} {

}

PawnPiece::~PawnPiece() {

}

vector<Move> PawnPiece::getPieceMoves(BoardState& board) const { //TODO: add en passant, promotion
    
    vector<Move> moves; 


    int x = position_x;
    int y = position_y;
    int direction = isWhite ? 1 : -1;
    int new_y = y + direction;

    if (withinBounds(x,new_y) && board.board[new_y][x] == nullptr){
        addToMoveList(x,new_y,nullptr,moves);
        if ((isWhite && y == 1) || (!isWhite && y == 6)){
            int doubleMove = direction * 2;
            if (withinBounds(x,y + doubleMove) && board.board[y+doubleMove][x] == nullptr){
                addToMoveList(x,y+doubleMove,nullptr,moves);
            }
        }
    }
    int new_x = x+1;

    if (withinBounds(new_x,new_y) && board.board[new_y][new_x] != nullptr && (board.board[new_y][new_x]->isWhite != isWhite) ){
        addToMoveList(new_x,new_y,board.board[new_y][new_x],moves);
    }

    new_x = x-1;
    if (withinBounds(new_x,new_y) && board.board[new_y][new_x] != nullptr && (board.board[new_y][new_x]->isWhite != isWhite) ){
        addToMoveList(new_x,new_y,board.board[new_y][new_x],moves);
    }
    
    enPassant(board,moves);
    return moves;

}

bool PawnPiece::isAttacking(int x, int y, BoardState& board) const {
    int direction = isWhite ? 1 : -1;

    if (y == position_y + direction && (x == position_x + 1 || x == position_x - 1)){
        return true;
    }

    return false;
}


void PawnPiece::enPassant(BoardState& board, vector<Move>& moves) const {
    if (board.lastMoves.empty()){
        return;
    }
    int x = position_x;
    int y = position_y;
    int lastMoveStarty = board.lastMoves.back().getFrom().second;

    int lastMoveEndx = board.lastMoves.back().getTo().first;
    int lastMoveEndy = board.lastMoves.back().getTo().second;
    
    if (
        y == lastMoveEndy && abs(lastMoveEndx - x) == 1
        && board.board[y][lastMoveEndx] != nullptr 
        && board.board[y][lastMoveEndx]->getType() == PAWN
        && abs(lastMoveEndy - lastMoveStarty) == 2
    ) {
        moves.push_back(Move{
            {lastMoveEndx,(lastMoveStarty + lastMoveEndy)/2},
            {x,y},
            board.board[lastMoveEndy][lastMoveEndx]
        });
    }
}

void PawnPiece::addToMoveList(int new_x, int new_y, Piece* pieceCaptured, vector<Move>& moves) const {
    int x = position_x;
    int y = position_y;
    char blackPromotions[4] = {'q','r','b','n'};
    char whitePromotions[4] = {'Q','R','B','N'};
    if (isWhite && y == 7){
        for (auto promotion : whitePromotions){
            moves.push_back(Move{{new_x,new_y},{x,y},pieceCaptured, promotion});
        }
    } else if (!isWhite && y == 0){
        for (auto promotion : blackPromotions){
            moves.push_back(Move{{new_x,new_y},{x,y},pieceCaptured,promotion});
        }
    } else {
        moves.push_back(Move{{new_x,new_y},{x,y}, pieceCaptured});
    }
}

double PawnPiece::getValue() {
    return value;
}

PieceType PawnPiece::getType() {
    return PAWN;
}
