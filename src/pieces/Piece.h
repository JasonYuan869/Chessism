#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "../Move.h"
#include "../BoardState.h"
#include "../Utility.h"

enum PieceType {
    PAWN = 0,
    ROOK = 1,
    KNIGHT = 2,
    BISHOP = 3,
    QUEEN = 4,
    KING = 5,
    EMPTY = 6,
};

// Forward declarations for circular dependencies
class Move;

class BoardState;

class Piece {
public:
    double value;
    PieceType type;
    int x;
    int y;
    bool isWhite;
    bool isAlive;
    bool canCastle;
    std::vector<Move> validMoves;

    Piece(int x, int y, bool isWhite, bool canCastle = false);

    virtual ~Piece() = default;

    virtual std::vector<Move> getPieceMoves(BoardState& board) const = 0;

    virtual bool isAttacking(int x, int y, BoardState& board) const = 0;

    virtual double getValue() = 0;

    virtual PieceType getType() = 0;

    std::pair<int, int> getPosition() const;

    void setPosition(int x, int y);
};

#endif
