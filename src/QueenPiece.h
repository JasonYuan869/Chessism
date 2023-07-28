#ifndef QUEENPIECE_H
#define QUEENPIECE_H

#include <vector>
#include "Move.h"
#include "BoardState.h"



class QueenPiece : public Piece {
public:
    static double value;

    QueenPiece(int,int,bool);

    ~QueenPiece() override;

    std::vector <Move> getPieceMoves(BoardState &board) const override;

    bool isAttacking(int x, int y, BoardState &board) const override;
    double getValue() override;
    PieceType getType() override;

};

#endif