#include "HumanPlayer.h"

#include <iostream>
#include <vector>

using namespace std;

HumanPlayer::HumanPlayer(bool isWhite): Player{isWhite} {}

MoveResult HumanPlayer::makeMove(BoardState& board) {
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
        if (from_pair.first < 0 || from_pair.first > 7 || from_pair.second < 0 || from_pair.second > 7 ||
            to_pair.first < 0 || to_pair.first > 7 || to_pair.second < 0 || to_pair.second > 7) {
                cout << "Invalid location" << endl;
                return MoveResult::INVALID_MOVE;
        }
        // if (board.board[from_y][from_x] != nullptr && board.board[from_y][from_x]->getType() == PAWN){
            
        // }
        Move m{to_pair, from_pair};
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
