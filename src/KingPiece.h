#ifndef KINGPIECE_H
#define KINGPIECE_H

#include <vector>
#include "Move.h"
#include "BoardState.h"

using namespace std;

class KingPiece : public Piece {
    bool checked;
    bool canCastle;
public:
    static double value;

    KingPiece();

    ~KingPiece();

    vector <Move> getPieceMoves(BoardState &board) override;

    bool isAttacking(int x, int y, BoardState &board) override;
};

#endif
