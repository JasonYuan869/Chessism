#include "Piece.h"

using namespace std;

Piece::~Piece() {}

bool Piece::withinBounds(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

std::pair<int, int> Piece::getPosition() const {
    return pair<int, int>{positionX, positionY};
}
void Piece::setPosition(int x,int y){
    positionX = x;
    positionY = y;
    return;
}

Piece::Piece(int x, int y, bool isWhite, bool canCastle) : positionX{x}, positionY{y}, isWhite{isWhite},
                                                           isAlive{true}, canCastle{canCastle} {}