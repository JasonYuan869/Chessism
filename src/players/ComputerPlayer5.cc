#include "ComputerPlayer5.h"
#include "../pieces/KingPiece.h"

using namespace std;

#define COMPUTER5_DEPTH 4

ComputerPlayer5::ComputerPlayer5(bool isWhite) : Player{isWhite} {}

bool ComputerPlayer5::makeMove(BoardState& board) {
    Move m = determineBestMove(board);
    board.movePiece(m);
    return true;
}

double ComputerPlayer5::evaluateBoard(BoardState& board) {
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

    // Add points for being in check
    KingPiece* king = board.isWhiteTurn ? board.whiteKing : board.blackKing;
    if (board.getAttacked(king->x, king->y, board.isWhiteTurn)) {
        eval += isWhite == board.isWhiteTurn ? -2 : 2;
    }

    return eval;
}

double ComputerPlayer5::alphabeta(int depth, BoardState& board, double alpha, double beta, bool isMaximizingPlayer) {
    if (depth == 0) {
        return evaluateBoard(board);
    }

    // Update valid moves for current turn
    board.updateValidMoves();

    double best = isMaximizingPlayer ? -9999 : 9999;
    vector<Move> validMoves = board.allValidMoves();
    if (isMaximizingPlayer) {
        for (auto& move : validMoves) {
            board.movePiece(move);
            double value = alphabeta(depth - 1, board, alpha, beta, false);
            board.undo();
            best = max(best, value);
            alpha = max(alpha, best);
            if (value >= beta) {
                break;
            }
        }
    } else {
        for (auto& move : validMoves) {
            board.movePiece(move);
            double value = alphabeta(depth - 1, board, alpha, beta, true);
            board.undo();
            best = min(best, value);
            beta = min(beta, best);
            if (value <= alpha) {
                break;
            }
        }
    }

    return best;
}

void ComputerPlayer5::getHelp(BoardState& board) {
    cout
            << "Hi! I'm a Level 5 computer bot and it's my turn to move. I search for optimal moves up to "
            << COMPUTER5_DEPTH
            << " moves ahead, and choose the best one to play. Type in \"move\" when you want me to play my turn."
            << endl;
}

void ComputerPlayer5::getHint(BoardState& board) {
    cout << "I'm thinking..." << endl;
    Move m = determineBestMove(board);

    char to_x = m.to.first + 'a';
    char to_y = m.to.second + '1';
    char from_x = m.from.first + 'a';
    char from_y = m.from.second + '1';

    cout << "I think you should move from " << from_x << from_y << " to " << to_x << to_y << endl;
}

Move ComputerPlayer5::determineBestMove(BoardState& board) {
    double best = -9999;
    vector<pair<Move, double>> positions;

    vector<Move> validMoves = board.allValidMoves();
    for (const Move& m : validMoves) {
        board.movePiece(m);
        double value = alphabeta(COMPUTER5_DEPTH - 1, board, -9999, 9999, false);
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
    return bestMoves.at(randomIndex);
}
