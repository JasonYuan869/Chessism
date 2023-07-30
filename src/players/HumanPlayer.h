#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include "../BoardState.h"

class HumanPlayer : public Player {
    static char getPromotion(BoardState &board, std::pair<int,int> to, std::pair<int,int> from);
public:
    explicit HumanPlayer(bool isWhite);

    MoveResult makeMove(BoardState &board) override;
};

#endif
