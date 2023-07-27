#ifndef PAWNPIECE_H
#define PAWNPIECE_H

#include <vector>
#include "Move.h"
#include "BoardState.h"

using namespace std;

class PawnPiece : public Piece {
    void enPassant(BoardState &board,vector<Move>& moves);
    void addToMoveList(int,int,vector<Move>&);

public:
    static double value;

    PawnPiece(int,int,bool);

    ~PawnPiece();

    vector <Move> getPieceMoves(BoardState &board) override;
    bool isAttacking(int x, int y, BoardState &board) override;
    double getValue() override;

    Piece* promote()

};

#endif
