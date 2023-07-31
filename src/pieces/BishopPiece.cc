#include "BishopPiece.h"

using namespace std;

double BishopPiece::value = 3.0;
PieceType BishopPiece::type = PieceType::BISHOP;

BishopPiece::BishopPiece(int x, int y, bool isWhite) : Piece{x, y, isWhite} {}

vector<Move> BishopPiece::getPieceMoves(BoardState& board) const {
    vector<Move> moves;

    int directions[2][2] = {{1, 1},
                            {1, -1}};

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
                moves.emplace_back(make_pair(tempx, tempy), make_pair(x, y));
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
                moves.emplace_back(make_pair(tempx, tempy), make_pair(x, y));
                tempx -= direction[0];
                tempy -= direction[1];
            }
        }
    }
    return moves;
}

bool BishopPiece::isAttacking(int x, int y, BoardState& board) const {
    int directions[2][2] = {{1, 1},
                            {1, -1}};


    for (auto& direction : directions) {

        int tempx = x + direction[0];
        int tempy = y + direction[1];
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

        tempx = x - direction[0];
        tempy = y - direction[1];
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

double BishopPiece::getValue() {
    return value;
}

PieceType BishopPiece::getType() {
    return type;
}
