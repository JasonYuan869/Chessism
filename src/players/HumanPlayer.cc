#include "HumanPlayer.h"
#include "../utility.h"
#include <iostream>
#include <vector>

using namespace std;

HumanPlayer::HumanPlayer(bool isWhite): Player{isWhite} {}

MoveResult HumanPlayer::makeMove(BoardState& board) {
    vector<Move> moves = allValidMoves(board); // get valid moves from player

    int numMoves = moves.size();
    if (numMoves == 0) {
        return MoveResult::STALEMATE;
    }

    string command;

    cin >> command;

    if (cin.eof()) {
        throw -1;
    }

    if (command == "resign") {
        return MoveResult::RESIGNED;
    } else if (command == "setup") {
        return MoveResult::SETUP;
    } else if (command == "move") {
        string from, to;
        cin >> from >> to;
        if (from.size() != 2 || to.size() != 2) {
            cout << "Invalid input" << endl;
            return MoveResult::INVALID_MOVE;
        }
        int from_x = from[0] - 'a';
        int from_y = from[1] - '1';
         
        int to_x = to[0] - 'a';
        int to_y = to[1] - '1';


        pair<int, int> from_pair = {from_x, from_y};
        pair<int, int> to_pair = {to_x, to_y};

        // check bounds
        if (!Utility::withinBounds(from_x,from_y) || !Utility::withinBounds(to_x,to_y)) {
            cout << "Invalid location" << endl;
            return MoveResult::INVALID_MOVE;
        }
        char promotionPiece = getPromotion(board,to_pair,from_pair);
       
        Move m{to_pair, from_pair, promotionPiece};
        bool success = board.movePieceIfLegal(m);
        if (success) {
            return MoveResult::SUCCESS;
        } else {
            cout << "Invalid move" << endl;
            return MoveResult::INVALID_MOVE;
        }
    } else {
        cout << "Invalid input" << endl;
        return MoveResult::INVALID_MOVE;
    }
}



char HumanPlayer::getPromotion(BoardState &board, pair<int,int> to, pair<int,int> from){
    int to_x = to.first;
    int to_y = to.second;
    int from_x = from.first;
    int from_y = from.second;
    char promotionPiece = '-';

    if (board.board[from_y][from_x] != nullptr 
        && board.board[from_y][from_x]->getType() == PAWN
        && (to_y == 7 || to_y == 0)){
        cin >> promotionPiece;
    }
    return promotionPiece;
}


