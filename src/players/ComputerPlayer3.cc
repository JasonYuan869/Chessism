#include "ComputerPlayer3.h"
#include <algorithm>
#include <cmath>
#include "../pieces/KingPiece.h"
#include "../utility.h"

using namespace std;

ComputerPlayer3::ComputerPlayer3(bool isWhite): Player{isWhite} {}
ComputerPlayer3::~ComputerPlayer3() {}

MoveResult ComputerPlayer3::makeMove(BoardState& board) {
    double highestScore = -9999;

    vector<pair<Move, double>> positions;
    vector<Piece*> pieces = isWhite ? board.whitePieces : board.blackPieces;

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
            if (board.getAttacked(enemyKing->positionX, enemyKing->positionY, !isWhite)) {
                scoredMove.second += 0.5;
            }

            // Subtract most valuable attacked
            scoredMove.second -= mostValuableAttacked(board);
            board.undo();
            positions.push_back(scoredMove);

            // Update the highest score
            if (scoredMove.second > highestScore) {
                highestScore = scoredMove.second;
            }
        }
    }

    if (positions.empty()) {
        return MoveResult::STALEMATE;
    }

    // Randomly choose a move with the highest score
    vector<Move> bestMoves;
    for (const pair<Move, double>& p : positions) {
        if (Utility::doubleEquality(p.second, highestScore)) {
            bestMoves.push_back(p.first);
        }
    }

    int randomIndex = Utility::randomInt(0, bestMoves.size() - 1);

    Move m = bestMoves.at(randomIndex);

    board.movePiece(m);
    return MoveResult::SUCCESS;
}

double ComputerPlayer3::mostValuableAttacked(BoardState& board) {
    // Update valid moves for opponent
    board.updateValidMoves(!isWhite);

    double maxScore = 0;
    vector<Piece*> pieces = isWhite ? board.blackPieces : board.whitePieces;

    // For each opponent piece, check which piece it can attack with the highest value
    for (Piece* p : pieces) {
        if (!p->isAlive) {
            continue;
        }
        vector<Move> moves = p->validMoves;
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
