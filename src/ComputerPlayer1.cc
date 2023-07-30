#include "ComputerPlayer1.h"
using namespace std;
ComputerPlayer1::ComputerPlayer1(bool isWhite): Player{isWhite} {}
ComputerPlayer1::~ComputerPlayer1() {

}

MoveResult ComputerPlayer1::makeMove(BoardState& board) {
    string command;
    cin >> command;

    if (cin.eof()) {
        throw -1;
    }

    if (command == "move") {
        vector<Piece*> pieces;
        if (isWhite) {
            pieces = board.whitePieces;
        } else {
            pieces = board.blackPieces;
        }

        int numPieces = pieces.size();
        int randomPiece = rand() % numPieces;

        vector<Move> moves = pieces.at(randomPiece)->validMoves;
        int numMoves = moves.size();
        int randomMove = rand() % numMoves;

        Move m = moves.at(randomMove);
        board.movePiece(m);
        return MoveResult::SUCCESS;
    } else if (command == "setup") {
        return MoveResult::SETUP;
    }

    return MoveResult::INVALID_MOVE;
}
