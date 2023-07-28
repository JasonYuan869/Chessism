#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "Move.h"
#include "BoardState.h"

// Forward declarations for circular dependencies
class Move;
class BoardState;

class Piece {
public:
    int position_x;
    int position_y;
    bool isWhite;
    bool isAlive;
    bool canCastle;
    std::vector<Move> validMoves;

    static bool withinBounds(int x, int y); //returns true if the position is inside the board
    Piece(int x ,int y,bool isWhite,bool canCastle = false);
    virtual ~Piece();

    virtual std::vector<Move> getPieceMoves(BoardState &board) const = 0;

    virtual bool isAttacking(int x, int y, BoardState &board) const = 0;
    virtual double getValue() = 0;

    std::pair<int, int> getPosition() const;
};

#endif
