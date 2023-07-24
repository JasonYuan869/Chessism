#include "Piece.h"
#include "PawnPiece.h"
#include "RookPiece.h"
#include "KnightPiece.h"
#include "BishopPiece.h"
#include "QueenPiece.h"
#include "KingPiece.h"

using namespace std;

bool Piece::withinBounds(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

std::pair<int, int> Piece::getPosition() const {
    return pair{position_x, position_y};
}

Piece::Piece(int x, int y,bool isWhite,bool canCastle = false): position_x{x},position_y{y},isWhite{isWhite},isAlive{true},canCastle{canCastle}{}

Piece *makePiece(char piece, int x, int y) {
    switch (piece) {
        case 'P':
            return new PawnPiece(x, y, true);
        case 'p':
            return new PawnPiece(x, y, false);
        case 'R':
            return new RookPiece(x, y, true);
        case 'r':
            return new RookPiece(x, y, false);
        case 'N':
            return new KnightPiece(x, y, true);
        case 'n':
            return new KnightPiece(x, y, false);
        case 'B':
            return new BishopPiece(x, y, true);
        case 'b':
            return new BishopPiece(x, y, false);
        case 'Q':
            return new QueenPiece(x, y, true);
        case 'q':
            return new QueenPiece(x, y, false);
        case 'K':
            return new KingPiece(x, y, true);
        case 'k':
            return new KingPiece(x, y, false);
    }
}