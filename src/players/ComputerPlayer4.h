#ifndef COMPUTERPLAYER4_H
#define COMPUTERPLAYER4_H

#include "Player.h"
#include "../BoardState.h"

class ComputerPlayer4 : public Player {
public:
    explicit ComputerPlayer4(bool isWhite);

    bool makeMove(BoardState &board) override;

    double minimax(int depth, BoardState &board, bool isMaximizingPlayer);
    void getHelp(BoardState &board) override;
};

#endif
