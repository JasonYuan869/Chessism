#include "RookPiece.h"

using namespace std;

double RookPiece::value = 5;

RookPiece::RookPiece(int x, int y, bool isWhite) : Piece{x, y, isWhite, true} {}

vector<Move> RookPiece::getPieceMoves(BoardState &board) const {
    vector<Move> moves;
    int x = positionX;
    int y = positionY;
    int directions[2][2] = {{0, 1},
                            {1, 0}};

    for (auto &direction: directions) {

        int tempx = x + direction[0];
        int tempy = y + direction[1];
        while (Utility::withinBounds(tempx, tempy)) {
            if (board.board[tempy][tempx] != nullptr) {
                if (board.board[tempy][tempx]->isWhite != isWhite) {
                    // If the rook is able to castle, any move should disable that ability
                    // If the rook already cannot castle, then this will have no effect
                    moves.emplace_back(
                            make_pair(tempx, tempy),
                            make_pair(x, y),
                            canCastle,
                            board.board[tempy][tempx]
                    );
                }
                break;
            } else {
                moves.emplace_back(
                        make_pair(tempx, tempy),
                        make_pair(x, y),
                        canCastle
                );
                tempx += direction[0];
                tempy += direction[1];
            }
        }

        tempx = x - direction[0];
        tempy = y - direction[1];
        while (Utility::withinBounds(tempx, tempy)) {
            //check if there is a piece, if yes, and the piece is opposite color, then 
            //we can add a capture.
            if (board.board[tempy][tempx] != nullptr) {
                if (board.board[tempy][tempx]->isWhite != isWhite) {
                    moves.emplace_back(
                            make_pair(tempx, tempy),
                            make_pair(x, y),
                            canCastle,
                            board.board[tempy][tempx]
                    );
                }
                break;
            } else {
                moves.emplace_back(
                        make_pair(tempx, tempy),
                        make_pair(x, y),
                        canCastle
                );
                tempx -= direction[0];
                tempy -= direction[1];
            }
        }
    }
    return moves;
}

bool RookPiece::isAttacking(int x, int y, BoardState &board) const {
    int directions[2][2] = {{0, 1},
                            {1, 0}};

    for (auto &direction: directions) {

        int tempx = positionX + direction[0];
        int tempy = positionY + direction[1];
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

        tempx = positionX - direction[0];
        tempy = positionY - direction[1];
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

double RookPiece::getValue() {
    return value;
}

PieceType RookPiece::getType() {
    return ROOK;
}
