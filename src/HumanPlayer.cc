#include "HumanPlayer.h"
#include "BoardState.h"
#include "Move.h"

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

HumanPlayer::HumanPlayer(bool isWhite): Player{isWhite} {}

int HumanPlayer::makeMove(BoardState& board) {
    string command;

    cin >> command;

    if (cin.eof()) {
        throw -1;
    }

    if (command == "resign") {
        return 3;
    } else if (command == "setup") {
        return 4;
    } else if (command == "move") {
        string from, to;
        cin >> from >> to;
        if (from.size() != 2 || to.size() != 2) {
            cout << "Invalid input" << endl;
            return 0;
        }
        pair<int, int> from_pair = {from[0] - 'a', from[1] - '1'};
        pair<int, int> to_pair = {to[0] - 'a', to[1] - '1'};
        
        Move m{to_pair, from_pair};
        bool success = board.movePieceIfLegal(m);
        if (success) {
            return 1;
        } else {
            cout << "Invalid move" << endl;
            return 0;
        }
    } else {
        cout << "Invalid input" << endl;
        return 0;
    }
}
