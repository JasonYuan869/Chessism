#include "Player.h"
#include "../pieces/KingPiece.h"

using namespace std;

Player::Player(bool isWhite) : isWhite{isWhite} {}

double Player::evaluateBoard(BoardState& board) const {
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

        // Add points for being in checkmate
        if (board.getStalemate(board.isWhiteTurn)) {
            eval += isWhite == board.isWhiteTurn ? -1000 : 1000;
        }
    }

    return eval;
}

