#include "KnightPiece.h"

using namespace std;

double KnightPiece::value = 2.7;

KnightPiece::KnightPiece(int x, int y, bool isWhite) : Piece{x, y, isWhite} {}

vector<Move> KnightPiece::getPieceMoves(BoardState& board) const {
    int directions[4] = {2, 1, -1, -2};
    vector<Move> moves;

    for (auto& xdirection : directions) {
        for (auto& ydirection : directions) {
            if (abs(xdirection) + abs(ydirection) == 3) {
                int new_x = x + xdirection;
                int new_y = y + ydirection;
                if (Utility::withinBounds(new_x, new_y) &&
                    (board.board[new_y][new_x] == nullptr || (board.board[new_y][new_x]->isWhite != isWhite))) {
                    moves.emplace_back(make_pair(new_x, new_y), make_pair(x, y), board.board[new_y][new_x]);
                }
            }
        }
    }
    return moves;
}

bool KnightPiece::isAttacking(int x, int y, BoardState& board) const {
    int directions[4] = {2, 1, -1, -2};

    for (auto& xdirection : directions) {
        for (auto& ydirection : directions) {
            if (abs(xdirection) + abs(ydirection) == 3) {
                int new_x = x + xdirection;
                int new_y = y + ydirection;
                if (new_x == x && new_y == y) {
                    return true;
                }
            }
        }
    }
    return false;
}

double KnightPiece::getValue() {
    return value;
}

PieceType KnightPiece::getType() {
    return KNIGHT;
}
