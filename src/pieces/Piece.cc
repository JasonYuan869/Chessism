#include "Piece.h"

using namespace std;

std::pair<int, int> Piece::getPosition() const {
    return pair<int, int>{x, y};
}

void Piece::setPosition(int x, int y) {
    x = x;
    y = y;
    return;
}

Piece::Piece(int x, int y, bool isWhite, bool canCastle) : x{x}, y{y}, isWhite{isWhite},
                                                           isAlive{true}, canCastle{canCastle} {}