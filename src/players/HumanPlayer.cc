#include "HumanPlayer.h"
#include "../utility.h"
#include <iostream>
#include <vector>

using namespace std;

HumanPlayer::HumanPlayer(bool isWhite): Player{isWhite} {}

MoveResult HumanPlayer::makeMove(BoardState& board) {
    vector<Move> moves = board.allValidMoves(); // get valid moves from player

    int numMoves = moves.size();
    if (numMoves == 0) {
        return MoveResult::STALEMATE;
    }

    string from, to;
    cin >> from >> to;

    if (cin.eof()) {
        throw -1;
    }

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
}

char HumanPlayer::getPromotion(BoardState &board, pair<int,int> to, pair<int,int> from) {
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

void HumanPlayer::getHelp(BoardState &board){
    string colour = isWhite ? "white" : "black";
    cout<<"it is "<< colour << "\'s turn. Enter a tile and I can help further, or enter any other command to quit."<<endl;
    string input;
    cin>>input;
    if (cin.eof()) {
        throw -1;
    }

    if (input.size() != 2 ) {
        return;
    }

    int x = input[0] - 'a';
    int y = input[1] - '1';
    if (Utility::withinBounds(x,y) && board.board[y][x] != nullptr){
        Piece* piece = board.board[y][x];
        int type = piece->getType();
        string names[6] = {"pawn","rook","knight","bishop","queen","king"};
        string color = piece->isWhite ? "white" : "black";
        cout<<"this is a "<< color << " " << names[type] << "." <<endl;
        vector<Move> moves = piece->validMoves;
        if (moves.size() == 0){
            cout<< "there are no moves for this piece."<<endl;
        } else {
            cout<<"It can move to : ";
            for (auto& move : moves){
                int to_x = move.to.first;
                int to_y = move.to.second;
                cout<<string(1,'a'+to_x) <<string(1,'1'+to_y)<<"  ";
            }
            cout<<endl;
        }
    }    
}
