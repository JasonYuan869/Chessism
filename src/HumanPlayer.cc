#include "HumanPlayer.h"
#include "BoardState.h"
#include "Move.h"

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

HumanPlayer::HumanPlayer(bool isWhite): Player{isWhite} {}

int HumanPlayer::makeMove(BoardState& board) {
    string c, s;
    vector<string> command;
    stringstream ss(c);
 
    while (getline(ss, s, ' ')) { 
        command.push_back(s);
    }

    if (command.empty()) {
        cout << "Invalid input" << endl;
        return 0;
    }

    if (command.at(0) == "resign") {
        return 3;
    } else if (command.at(0) == "move" && command.size() == 3) {
        string from, to;
        from = command.at(1);
        to = command.at(2);
        if (from.size() != 2 || to.size() != 2) {
            cout << "Invalid input" << endl;
            return 0;
        }
        pair<int, int> from_pair = {from[0], from[1]};
        pair<int, int> to_pair = {to[0], to[1]};
        Move m{to_pair, from_pair};
        board.movePiece(m);
        return 1;
    } else {
        cout << "Invalid input" << endl;
        return 0;
    }
}
