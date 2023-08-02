#include "QueenPiece.h"

using namespace std;

double QueenPiece::value = 9;
PieceType QueenPiece::type = PieceType::QUEEN;

QueenPiece::QueenPiece(int x, int y, bool isWhite) : Piece{x, y, isWhite} {}

vector<Move> QueenPiece::getPieceMoves(BoardState& board) const {
    int directions[4][2] = {{1, 1},
                            {1, -1},
                            {0, 1},
                            {1, 0}};
    vector<Move> moves;

    for (auto& direction : directions) {

        int tempx = x + direction[0];
        int tempy = y + direction[1];
        while (Utility::withinBounds(tempx, tempy)) {
            if (board.board[tempy][tempx] != nullptr) {
                if (board.board[tempy][tempx]->isWhite != isWhite) {
                    moves.emplace_back(
                            make_pair(tempx, tempy),
                            make_pair(x, y),
                            board.board[tempy][tempx]
                    );
                }
                break;
            } else {
                moves.emplace_back(
                        make_pair(tempx, tempy),
                        make_pair(x, y)
                );
                tempx += direction[0];
                tempy += direction[1];
            }
        }

        tempx = x - direction[0];
        tempy = y - direction[1];
        while (Utility::withinBounds(tempx, tempy)) {
            if (board.board[tempy][tempx] != nullptr) {
                if (board.board[tempy][tempx]->isWhite != isWhite) {
                    moves.emplace_back(
                            make_pair(tempx, tempy),
                            make_pair(x, y),
                            board.board[tempy][tempx]
                    );
                }
                break;
            } else {
                moves.emplace_back(
                        make_pair(tempx, tempy),
                        make_pair(x, y)
                );
                tempx -= direction[0];
                tempy -= direction[1];
            }
        }
    }
    return moves;
}

bool QueenPiece::isAttacking(int x, int y, BoardState& board) const {
    int directions[4][2] = {{1, 1},
                            {1, -1},
                            {0, 1},
                            {1, 0}};

    for (auto& direction : directions) {

        int tempx = this->x + direction[0];
        int tempy = this->y + direction[1];
        while (Utility::withinBounds(tempx, tempy)) {
            if (board.board[tempy][tempx] != nullptr) {
                if (board.board[tempy][tempx]->isWhite != isWhite) {
                    if (tempx == x && tempy == y) {
                        return true;
                    }
                }
                break;
            } else {
                if (tempx == x && tempy == y) {
                    return true;
                }
                tempx += direction[0];
                tempy += direction[1];
            }
        }

        tempx = this->x - direction[0];
        tempy = this->y - direction[1];
        while (Utility::withinBounds(tempx, tempy)) {
            if (board.board[tempy][tempx] != nullptr) {
                if (board.board[tempy][tempx]->isWhite != isWhite) {
                    if (tempx == x && tempy == y) {
                        return true;
                    }
                }
                break;
            } else {
                if (tempx == x && tempy == y) {
                    return true;
                }
                tempx -= direction[0];
                tempy -= direction[1];
            }
        }
    }
    return false;

}

double QueenPiece::getValue() {
    return value;
}

PieceType QueenPiece::getType() {
    return type;
}