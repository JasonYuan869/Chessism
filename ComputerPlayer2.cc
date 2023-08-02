#include "ComputerPlayer2.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "KingPiece.h"
#include "Utility.h"

using namespace std;

ComputerPlayer2::ComputerPlayer2(bool isWhite): ComputerPlayer{isWhite} {}

bool ComputerPlayer2::makeMove(BoardState& board) {
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
                scoredMove = {m, score};
            }

            // Check if the move puts the opponent in check
            KingPiece* enemyKing = isWhite ? board.blackKing : board.whiteKing;
            board.movePiece(m);
            if (board.getAttacked(enemyKing->x, enemyKing->y, !isWhite)) {
                scoredMove.second += 0.5;
            }
            board.undo();

            positions.push_back(scoredMove);
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


void ComputerPlayer2::getHelp(BoardState& board){
    cout<<"Hi! I'm a Level 2 computer bot and it's my turn to move. Type in \"move\" when you want me to play my turn." <<endl;
}
