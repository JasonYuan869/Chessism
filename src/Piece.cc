#include "Piece.h"

using namespace std;

Piece::~Piece() {}

bool Piece::withinBounds(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

std::pair<int, int> Piece::getPosition() const {
    return pair<int, int>{position_x, position_y};
}

Piece::Piece(int x, int y, bool isWhite, bool canCastle) : position_x{x}, position_y{y}, isWhite{isWhite},
                                                           isAlive{true}, canCastle{canCastle} {}