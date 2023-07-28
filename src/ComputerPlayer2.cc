#include "ComputerPlayer2.h"
#include "BoardState.h"
#include "Move.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

ComputerPlayer2::ComputerPlayer2(bool isWhite): Player{isWhite} {}

ComputerPlayer2::~ComputerPlayer2() {
    // do i have to do this lol
}

int ComputerPlayer2::makeMove(BoardState& board) {
    string command;
    cin >> command;
    if (command == "move") {
        vector<pair<Move, int>> positions;
        vector<Piece*> pieces;
        if (isWhite) {
            pieces = board.whitePieces;
        } else {
            pieces = board.blackPieces;
        }

        for (Piece* p : pieces) {
            vector<Move> moves = p->validMoves; // get valid moves from piece
            for (Move m : moves) {
                pair<int, int> to = m.getTo();
                if (board.board[to.first][to.second] == nullptr) {
                    pair<Move, int> thing{m, 0};
                    positions.push_back(thing);
                } else {
                    int score = abs(board.board[to.first][to.second]->getValue());
                    pair<Move, int> thing{m, score};
                    positions.push_back(thing);
                }
            }
        }

        std::sort(positions.begin(), positions.end(), [](auto &left, auto &right) {
            return left.second > right.second;
        });

        Move m = positions.at(0).first;
        board.movePiece(m);
        return 1;
    } else if (command == "setup") {
        return 4;
    }
    return 0;
}
