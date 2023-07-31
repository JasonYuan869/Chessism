#include "ComputerPlayer1.h"
#include "../Utility.h"

using namespace std;
ComputerPlayer1::ComputerPlayer1(bool isWhite): Player{isWhite} {}

MoveResult ComputerPlayer1::makeMove(BoardState& board) {
    vector<Move> moves = board.allValidMoves(); // get valid moves from player

    int numMoves = moves.size();
    if (numMoves == 0) {
        return MoveResult::STALEMATE;
    }

    int randomMove = Utility::randomInt(0, numMoves - 1);

    Move m = moves.at(randomMove);
    board.movePiece(m);
    return MoveResult::SUCCESS;
}



void ComputerPlayer1::getHelp(BoardState& board){
    cout << "Hi! I'm a Level 1 computer bot and it's my turn to move. I make moves randomly! Type in \"move\" when you want me to play my turn." << endl;
}
