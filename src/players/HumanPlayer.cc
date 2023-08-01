#include "HumanPlayer.h"
#include "../Utility.h"
#include <iostream>
#include <vector>

using namespace std;

HumanPlayer::HumanPlayer(bool isWhite) : Player{isWhite} {}

bool HumanPlayer::makeMove(BoardState& board) {
    string from, to;
    cin >> from >> to;

    if (cin.eof()) {
        throw -1;
    }

    if (from.size() != 2 || to.size() != 2) {
        cout << "Invalid input" << endl;
        return false;
    }
    int from_x = from[0] - 'a';
    int from_y = from[1] - '1';

    int to_x = to[0] - 'a';
    int to_y = to[1] - '1';


    pair<int, int> from_pair = {from_x, from_y};
    pair<int, int> to_pair = {to_x, to_y};

    // check bounds
    if (!Utility::withinBounds(from_x, from_y) || !Utility::withinBounds(to_x, to_y)) {
        cout << "Invalid location" << endl;
        return false;
    }
    char promotionPiece = getPromotion(board, to_pair, from_pair);

    Move m{to_pair, from_pair, promotionPiece};
    bool success = board.movePieceIfLegal(m);

    if (success) {
        return true;
    } else {
        cout << "Invalid move" << endl;
        return false;
    }
}

char HumanPlayer::getPromotion(BoardState& board, pair<int, int> to, pair<int, int> from) {
    int to_x = to.first;
    int to_y = to.second;
    int from_x = from.first;
    int from_y = from.second;
    char promotionPiece = '-';

    if (board.board[from_y][from_x] != nullptr
        && board.board[from_y][from_x]->getType() == PAWN
        && (to_y == 7 || to_y == 0)) {
        cin >> promotionPiece;
    }
    return promotionPiece;
}

void HumanPlayer::getHelp(BoardState& board) {
    string colour = isWhite ? "white" : "black";
    cout << "It is " << colour << "\'s turn. Enter a tile and I can help further, or enter any other command to quit."
         << endl;
    string input;
    cin >> input;
    if (cin.eof()) {
        throw -1;
    }

    if (input.size() != 2) {
        return;
    }

    int x = input[0] - 'a';
    int y = input[1] - '1';
    if (Utility::withinBounds(x, y) && board.board[y][x] != nullptr) {
        Piece* piece = board.board[y][x];
        int type = piece->getType();
        string names[6] = {"pawn", "rook", "knight", "bishop", "queen", "king"};
        string color = piece->isWhite ? "white" : "black";
        cout << "This is a " << color << " " << names[type] << "." << endl;
        if (piece->isWhite != board.isWhiteTurn){
            return;
        }
        vector<Move> moves = piece->validMoves;
        if (moves.size() == 0) {
            cout << "There are no moves for this piece." << endl;
        } else {
            cout << "It can move to: ";
            for (auto& move : moves) {
                int to_x = move.to.first;
                int to_y = move.to.second;
                if (move.promotion == '-'){
                    cout << (char) ('a' + to_x) << (char) ('1' + to_y) << "  ";
                } else {
                    string promotedPiece = "";
                    if (move.promotion == 'r' || move.promotion == 'R' ){
                        promotedPiece = "rook";
                    } else if (move.promotion == 'q' || move.promotion == 'Q' ){
                        promotedPiece = "queen";
                    } else if (move.promotion == 'b' || move.promotion == 'B' ){
                        promotedPiece = "bishop";
                    } else if (move.promotion == 'n' || move.promotion == 'N' ){
                        promotedPiece = "knight";
                    }
                    cout << (char) ('a' + to_x) << (char) ('1' + to_y) << " promoting to a " << promotedPiece << "|";
                }
            }
            cout << endl;
        }
    } else {
        if (!Utility::withinBounds(x,y)){
            cout << "that's not a tile on the board." << endl;
        } else {
            cout << "there is no piece on that tile." << endl;
        }
    }
}
