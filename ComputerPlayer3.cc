#include "ComputerPlayer3.h"
#include <algorithm>
#include <cmath>
#include "KingPiece.h"
#include "Utility.h"

using namespace std;

ComputerPlayer3::ComputerPlayer3(bool isWhite): ComputerPlayer{isWhite} {}

bool ComputerPlayer3::makeMove(BoardState& board) {
    double highestScore = -9999;

    vector<pair<Move, double>> positions;
    vector<unique_ptr<Piece>>& pieces = isWhite ? board.whitePieces : board.blackPieces;

    for (auto& p : pieces) {
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
            if (board.getAttacked(enemyKing->x, enemyKing->y, !isWhite)) {
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
    return true;
}

double ComputerPlayer3::mostValuableAttacked(BoardState& board) {
    // Update valid moves for opponent
    board.updateValidMoves();

    double maxScore = 0;
    vector<unique_ptr<Piece>>& pieces = isWhite ? board.blackPieces : board.whitePieces;

    // For each opponent piece, check which piece it can attack with the highest value
    for (auto& p : pieces) {
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



void ComputerPlayer3::getHelp(BoardState& board){
    cout<<"Hi! I'm a Level 3 computer bot and it's my turn to move. Type in \"move\" when you want me to play my turn." <<endl;
}
