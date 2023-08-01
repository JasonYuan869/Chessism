#ifndef COMPUTERPLAYER5_H
#define COMPUTERPLAYER5_H

#include "Player.h"
#include "../BoardState.h"

class ComputerPlayer5 : public Player {
public:
    explicit ComputerPlayer5(bool isWhite);

    bool makeMove(BoardState &board) override;

    double evaluateBoard(BoardState &board);

    void getHelp(BoardState &board) override;

    void getHint(BoardState &board);

    Move determineBestMove(BoardState& board);

    double alphabeta(int depth, BoardState& board, double alpha, double beta, bool isMaximizingPlayer);
};


#endif //COMPUTERPLAYER5_H
