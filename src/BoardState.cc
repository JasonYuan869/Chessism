#include "BoardState.h"
#include <iostream> 
#include <vector>

using namespace std;

BoardState::BoardState() {
    board = new Piece**[8];
    for (int i = 0; i < 8; i++) {
        board[i] = new Piece*[8];
    }

    // Initialize the board
    board[0][0] = Piece::makePiece('R', 0, 0);
    board[0][1] = Piece::makePiece('N', 0, 1);
    board[0][2] = Piece::makePiece('B', 0, 2);
    board[0][3] = Piece::makePiece('Q', 0, 3);
    board[0][4] = Piece::makePiece('K', 0, 4);
    board[0][5] = Piece::makePiece('B', 0, 5);
    board[0][6] = Piece::makePiece('N', 0, 6);
    board[0][7] = Piece::makePiece('R', 0, 7);

    for (int i = 0; i < 8; i++) {
        board[1][i] = Piece::makePiece('P', 1, i);
    }

    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = nullptr;
        }
    }

    for (int i = 0; i < 8; i++) {
        board[6][i] = Piece::makePiece('p', 6, i);
    }

    board[7][0] = Piece::makePiece('r', 7, 0);
    board[7][1] = Piece::makePiece('n', 7, 1);
    board[7][2] = Piece::makePiece('b', 7, 2);
    board[7][3] = Piece::makePiece('q', 7, 3);
    board[7][4] = Piece::makePiece('k', 7, 4);
    board[7][5] = Piece::makePiece('b', 7, 5);
    board[7][6] = Piece::makePiece('n', 7, 6);
    board[7][7] = Piece::makePiece('r', 7, 7);

    // Initialize the king pointers
    whiteKing = board[0][4];
    blackKing = board[7][4];

    // Initialize the piece vectors
    for (int i = 0; i < 16; i++) {
        whitePieces.push_back(board[0][i]);
        whitePieces.push_back(board[1][i]);

        blackPieces.push_back(board[6][i]);
        blackPieces.push_back(board[7][i]);
    }
}

BoardState::~BoardState() {
    // Delete pieces then delete the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;
}

bool BoardState::getCheckmate(bool white) {

}

bool BoardState::getCheck(bool white, int x, int y) {

}

void BoardState::updateValidMoves(bool white) {

}

bool BoardState::movePiece(Move move) {

}
