#include "ComputerPlayer4.h"
#include <cmath>
using namespace std;

ComputerPlayer4::ComputerPlayer4(bool isWhite): Player{isWhite} {}
ComputerPlayer4::~ComputerPlayer4() {

}

MoveResult ComputerPlayer4::makeMove(BoardState& board) {
    string command;
    cin >> command;

    if (cin.eof()) {
        throw -1;
    }

    if (command == "move") {
        double best = 0;
        Move bestmove;
        int depth = 3;

        vector<Piece*> pieces;
        if (isWhite) {
            pieces = board.whitePieces;
        } else {
            pieces = board.blackPieces;
        }

        for (Piece* p : pieces) {
            vector<Move> moves = p->validMoves; // get valid moves from piece
            for (const Move& m : moves) {
                board.movePiece(m);
                double value = minimax(depth - 1, board, true);
                board.undo();
                if (value >= best) {
                    best = value;
                    bestmove = m;
                }
            }
        }

        if (bestmove.getTo() == make_pair(-1, -1)) {
            return MoveResult::STALEMATE;
        }

        if (bestmove.getTo().first != -1 && bestmove.getTo().second != -1) {
            board.movePiece(bestmove);
            return MoveResult::SUCCESS;
        }
    } else if (command == "setup") {
        return MoveResult::SETUP;
    }

    return MoveResult::INVALID_MOVE;
}

int ComputerPlayer4::evaluateBoard(BoardState& board) {
    int eval = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board.board[i][j] != nullptr) {
                if ((board.board[i][j]->isWhite && isWhite) ||
                    (board.board[i][j]->isWhite && !isWhite)) {
                        eval += board.board[i][j]->getValue();
                } else {
                    eval -= board.board[i][j]->getValue();
                }
            }
        }
    }
    return eval;
}

double ComputerPlayer4::minimax(int depth, BoardState& board, bool isMaximizingPlayer) {
    // update valid moves
    board.updateValidMoves(true);
    board.updateValidMoves(false);

    if (depth == 0) {
        return -1 * evaluateBoard(board);
    }

    vector<Piece*> pieces;
    if (isWhite) {
        pieces = board.whitePieces;
    } else {
        pieces = board.blackPieces;
    }

    for (Piece* p : pieces) {
        vector<Move> moves = p->validMoves; // get valid moves from piece
        for (const Move& m : moves) {
            if (isMaximizingPlayer) {
                double best = 0;
                board.movePiece(m);
                best = fmax(best, minimax(depth - 1, board, false));
                board.undo();
                return best;
            } else {
                double best = 9999;
                board.movePiece(m);
                best = fmin(best, minimax(depth - 1, board, true));
                board.undo();
                return best;
            }
        }
    }
    return 0;
}
