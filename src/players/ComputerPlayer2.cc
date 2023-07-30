#include "ComputerPlayer2.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

ComputerPlayer2::ComputerPlayer2(bool isWhite): Player{isWhite} {}

ComputerPlayer2::~ComputerPlayer2() {}

MoveResult ComputerPlayer2::makeMove(BoardState& board) {
    string command;
    cin >> command;

    if (cin.eof()) {
        throw -1;
    }

    if (command == "move") {
        vector<pair<Move, double>> positions;
        vector<Piece*> pieces;
        if (isWhite) {
            pieces = board.whitePieces;
        } else {
            pieces = board.blackPieces;
        }

        for (Piece* p : pieces) {
            if (!p->isAlive) {
                continue;
            }
            vector<Move> moves = p->validMoves; // get valid moves from piece
            for (const Move& m : moves) {
                pair<int, int> to = m.getTo();
                pair<Move, double> scoredMove{m, 0};
                if (board.board[to.second][to.first] != nullptr) {
                    double score = board.board[to.second][to.first]->getValue();
                    scoredMove = {m, score};
                }
                positions.push_back(scoredMove);
            }
        }

        if (positions.empty()) {
            return MoveResult::STALEMATE;
        }

        std::sort(positions.begin(), positions.end(), [](auto &left, auto &right) {
            return left.second > right.second;
        });

        Move m = positions.at(0).first;
        board.movePiece(m);
        return MoveResult::SUCCESS;
    } else if (command == "setup") {
        return MoveResult::SETUP;
    }
    return MoveResult::INVALID_MOVE;
}
