#include "ComputerPlayer2.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "../pieces/KingPiece.h"
#include "../utility.h"

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

                // Check if the move puts the opponent in check
                KingPiece* enemyKing = isWhite ? board.blackKing : board.whiteKing;
                board.movePiece(m);
                if (board.getAttacked(enemyKing->position_x, enemyKing->position_y,!isWhite)) {
                    scoredMove.second += 0.5;
                }
                board.undo();

                positions.push_back(scoredMove);
            }
        }

        if (positions.empty()) {
            return MoveResult::STALEMATE;
        }


        // Randomly choose a move with the highest score
        vector<pair<Move, double>> bestMoves;
        double bestScore = positions.at(0).second;
        for (const pair<Move, double>& p : positions) {
            if (p.second == bestScore) {
                bestMoves.push_back(p);
            }
        }
        int randomIndex = Utility::randomInt(0, bestMoves.size() - 1);
        Move m = positions.at(randomIndex).first;

        board.movePiece(m);
        return MoveResult::SUCCESS;
    } else if (command == "setup") {
        return MoveResult::SETUP;
    }
    return MoveResult::INVALID_MOVE;
}
