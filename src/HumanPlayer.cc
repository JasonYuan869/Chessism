#include "HumanPlayer.h"
#include "BoardState.h"
#include "Move.h"

#include <iostream>
#include <vector>
#include <sstream>

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
        pair<int, int> from_pair = {from[0] - 'a', from[1] - '1'};
        pair<int, int> to_pair = {to[0] - 'a', to[1] - '1'};

        // check bounds
        if (from_pair.first < 0 || from_pair.first > 7 || from_pair.second < 0 || from_pair.second > 7 ||
            to_pair.first < 0 || to_pair.first > 7 || to_pair.second < 0 || to_pair.second > 7) {
                cout << "Invalid location" << endl;
                return MoveResult::INVALID_MOVE;
        }

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
