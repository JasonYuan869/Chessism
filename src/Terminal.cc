#include "Terminal.h"
#include <iostream>
using namespace std;

Terminal::Terminal(Game* game) : game{game} {
    // Register view as observer of model.
    game->attach(this);
}

Terminal::~Terminal() {}

void Terminal::notify() {
    BoardState& board = game->getBoard();

    for (int y = 7; y >= 0; y--) {
        cout << y+1 << ' ';
        for (int x = 0; x < 8; x++) {
            Piece* piece = board.board[y][x];
            if (piece == nullptr) {
                char blackOrWhite = (x + y) % 2 == 0 ? '_' : ' ';
                cout << blackOrWhite;
            } else {
                switch (piece->getType()) {
                    case PieceType::PAWN:
                        cout << (piece->isWhite ? 'P' : 'p');
                        break;
                    case PieceType::ROOK:
                        cout << (piece->isWhite ? 'R' : 'r');
                        break;
                    case PieceType::KNIGHT:
                        cout << (piece->isWhite ? 'N' : 'n');
                        break;
                    case PieceType::BISHOP:
                        cout << (piece->isWhite ? 'B' : 'b');
                        break;
                    case PieceType::QUEEN:
                        cout << (piece->isWhite ? 'Q' : 'q');
                        break;
                    case PieceType::KING:
                        cout << (piece->isWhite ? 'K' : 'k');
                        break;
                }
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "  abcdefgh" << endl;
}
