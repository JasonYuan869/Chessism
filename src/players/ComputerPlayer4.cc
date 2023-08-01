#include "ComputerPlayer4.h"
#include "../pieces/KingPiece.h"

using namespace std;

#define COMPUTER4_DEPTH 4

ComputerPlayer4::ComputerPlayer4(bool isWhite) : Player{isWhite} {}

bool ComputerPlayer4::makeMove(BoardState& board) {
    double best = -9999;
    vector<pair<Move, double>> positions;

    vector<Move> validMoves = board.allValidMoves();
    for (const Move& m : validMoves) {
        board.movePiece(m);
        double value = minimax(COMPUTER4_DEPTH - 1, board, false);
        board.undo();

        positions.emplace_back(m, value);
        if (value >= best) {
            best = value;
        }
    }

    vector<Move> bestMoves;
    for (const pair<Move, double>& p : positions) {
        if (Utility::doubleEquality(p.second, best)) {
            bestMoves.push_back(p.first);
        }
    }

    int randomIndex = Utility::randomInt(0, bestMoves.size() - 1);
    Move m = bestMoves.at(randomIndex);
    board.movePiece(m);
    return true;
}

double ComputerPlayer4::minimax(int depth, BoardState& board, bool isMaximizingPlayer) {
    if (depth == 0) {
        return evaluateBoard(board);
    }

    // Update valid moves for current turn
    board.updateValidMoves();

    double best = isMaximizingPlayer ? -9999 : 9999;

    vector<Move> validMoves = board.allValidMoves();
    for (auto& move : validMoves) {
        board.movePiece(move);
        double value = minimax(depth - 1, board, !isMaximizingPlayer);
        board.undo();
        if (isMaximizingPlayer) {
            best = max(best, value);
        } else {
            best = min(best, value);
        }
    }

    return best;
}


void ComputerPlayer4::getHelp(BoardState& board) {
    cout
            << "Hi! I'm a Level 4 computer bot and it's my turn to move. I search for every possible move up to "
            << COMPUTER4_DEPTH
            << " moves ahead, and choose the best one to play. Type in \"move\" when you want me to play my turn."
            << endl;
}