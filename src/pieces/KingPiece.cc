#include "KingPiece.h"

using namespace std;

double KingPiece::value = 1000;

KingPiece::KingPiece(int x, int y, bool isWhite) : Piece{x, y, isWhite, true}, checked{false} {}

vector<Move> KingPiece::getPieceMoves(BoardState &board) const {
    int directions[3] = {1, 0, -1};
    vector<Move> moves;
    int x = positionX;
    int y = positionY;
    for (auto xdirection: directions) {
        for (auto ydirection: directions) {
            if (xdirection != 0 || ydirection != 0) {
                int new_x = x + xdirection;
                int new_y = y + ydirection;
                if (Utility::withinBounds(new_x, new_y) &&
                    (board.board[new_y][new_x] == nullptr || (board.board[new_y][new_x]->isWhite != isWhite))) {
                    // If the king is able to castle, any move should disable that ability
                    // If the king already cannot castle, then this will have no effect
                    moves.emplace_back(make_pair(new_x, new_y), make_pair(x, y), canCastle, board.board[new_y][new_x]);
                }
            }
        }
    }


    // castle right
    if (canCastle && board.board[y][7] != nullptr && board.board[y][7]->canCastle) {
        bool rowEmpty = true;
        for (int i = x + 1; i < 7; i++) {
            if (board.board[y][i] != nullptr) {
                rowEmpty = false;
                break;
            }
        }

        if (rowEmpty && !board.getAttacked(x + 1, y, isWhite) && !board.getAttacked(x + 2, y, isWhite)) {
            moves.emplace_back(
                    make_pair(x + 2, y),
                    make_pair(x, y),
                    make_pair(x + 1, y),
                    make_pair(7, y),
                    board.board[y][7]
            );
        }
    }
    // castle left
    if (canCastle && board.board[y][0] != nullptr && board.board[y][0]->canCastle) {
        bool rowEmpty = true;
        for (int i = x - 1; i > 0; i--) {
            if (board.board[y][i] != nullptr) {
                rowEmpty = false;
                break;
            }
        }

        if (rowEmpty && !board.getAttacked(x - 1, y, isWhite) && !board.getAttacked(x - 2, y, isWhite)) {
            moves.emplace_back(
                    make_pair(x - 2, y),
                    make_pair(x, y),
                    make_pair(x - 1, y),
                    make_pair(0, y),
                    board.board[y][0]
            );
        }
    }

    return moves;
}

bool KingPiece::isAttacking(int x, int y, BoardState &board) const {

    int directions[3] = {1, 0, -1};

    for (auto xdirection: directions) {
        for (auto ydirection: directions) {
            if (xdirection != 0 || ydirection != 0) {
                int new_x = positionX + xdirection;
                int new_y = positionY + ydirection;
                if (new_x == x && new_y == y) {
                    return true;
                }
            }
        }
    }
    return false;
}

double KingPiece::getValue() {
    return value;
}

PieceType KingPiece::getType() {
    return KING;
}
