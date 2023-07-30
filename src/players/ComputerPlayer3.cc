#include "ComputerPlayer3.h"
#include <algorithm>
#include <cmath>
#include "../pieces/KingPiece.h"

using namespace std;

ComputerPlayer3::ComputerPlayer3(bool isWhite): Player{isWhite} {}
ComputerPlayer3::~ComputerPlayer3() {

}

MoveResult ComputerPlayer3::makeMove(BoardState& board) {
    string command;
    cin >> command;

    if (cin.eof()) {
        throw -1;
    }

    if (command == "move") {
        // Update valid moves for opponent
        board.updateValidMoves(!isWhite);

        vector<pair<Move, double>> positions;
        vector<Piece*> pieces;
        if (isWhite) {
            pieces = board.whitePieces;
        } else {
            pieces = board.blackPieces;
        }

        // Same logic as ComputerPlayer2
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
                    scoredMove.second = score;
                }

                // Check if the move puts the opponent in check
                KingPiece* enemyKing = isWhite ? board.blackKing : board.whiteKing;
                board.movePiece(m);
                if (board.getAttacked(enemyKing->position_x, enemyKing->position_y,!isWhite)) {
                    scoredMove.second += 0.5;
                }

                // subtract most valuable attacked
                scoredMove.second -= mostValuableAttacked(board);
                board.undo();
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

double ComputerPlayer3::mostValuableAttacked(BoardState& board) {
    double maxScore = 0;
    vector<Piece*> pieces;
    if (!isWhite) {
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
            if (board.board[to.second][to.first] != nullptr) {
                double score = board.board[to.second][to.first]->getValue();
                maxScore = fmax(score, maxScore);
            }
        }
    }

    return maxScore;
}
