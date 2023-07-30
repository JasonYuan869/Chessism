#include "ComputerPlayer4.h"
#include <cmath>
using namespace std;

#define DEPTH 3

ComputerPlayer4::ComputerPlayer4(bool isWhite): Player{isWhite} {}
ComputerPlayer4::~ComputerPlayer4() {}

MoveResult ComputerPlayer4::makeMove(BoardState& board) {
    double best = -9999;
    Move bestmove;

    vector<Move> validMoves = board.allValidMoves();
    for (const Move& m : validMoves) {
        board.movePiece(m);
        double value = minimax(DEPTH, board, false);
        board.undo();
        if (value >= best) {
            best = value;
            bestmove = m;
        }
    }

    if (bestmove.getTo() == make_pair(-1, -1)) {
        return MoveResult::STALEMATE;
    }

    board.movePiece(bestmove);
    return MoveResult::SUCCESS;
}

double ComputerPlayer4::evaluateBoard(BoardState& board) {
    double eval = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board.board[i][j] != nullptr) {
                double value = board.board[i][j]->getValue();
                if (isWhite != board.board[i][j]->isWhite) {
                    value *= -1;
                }
                eval += value;
            }
        }
    }
    return eval;
}

double ComputerPlayer4::minimax(int depth, BoardState& board, bool isMaximizingPlayer) {
    // Update valid moves for current turn
    board.updateValidMoves(board.isWhiteTurn);

    if (depth == 0) {
        return evaluateBoard(board);
    }

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
