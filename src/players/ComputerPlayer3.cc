#include "ComputerPlayer3.h"
#include <algorithm>
#include <cmath>

using namespace std;

ComputerPlayer3::ComputerPlayer3(bool isWhite): Player{isWhite} {}
ComputerPlayer3::~ComputerPlayer3() {

}

MoveResult ComputerPlayer3::makeMove(BoardState& board) {
    string command;
    cin >> command;

    if (cin.eof()) {
        throw -1;
    }

    if (command == "move") {
        vector<pair<Move, int>> positions;
        vector<Piece*> pieces;
        if (isWhite) {
            pieces = board.blackPieces;
        } else {
            pieces = board.whitePieces;
        }

        for (Piece* p : pieces) {
            vector<Move> moves = p->validMoves; // get valid moves from piece
            for (Move m : moves) {
                pair<int, int> to = m.getTo();
                if (board.board[to.first][to.second] == nullptr) {
                    pair<Move, int> thing{m, 0};
                    positions.push_back(thing);
                } else {
                    int score = abs(board.board[to.first][to.second]->getValue());
                    pair<Move, int> thing{m, score};
                    positions.push_back(thing);
                }
            }
        }

        if (positions.empty()) {
            return MoveResult::STALEMATE;
        }

        std::sort(positions.begin(), positions.end(), [](auto &left, auto &right) {
            return left.second > right.second;
        });

        Move m = positions.at(0).first;
        board.movePiece(m);
        return MoveResult::SUCCESS;
    } else if (command == "setup") {
        return MoveResult::SETUP;
    }

    return MoveResult::INVALID_MOVE;

    // evading next move captures, kinda unnecessary
    // vector<Piece*> pieces;
    // Move move;
    // int minvalue = 9999;
    // if (isWhite) {
    //     pieces = board.whitePieces;
    // } else {
    //     pieces = board.blackPieces;
    // }

    // for (Piece* p : pieces) {
    //     vector<Move> moves = p->validMoves; // get valid moves from piece
    //     for (Move m : moves) {
    //         int value = simulate(board, m);
    //         if (value < minvalue) {
    //             move = m;
    //             minvalue = value;
    //         }
    //     }
    // }

    // if (move.getTo().first != -1 && move.getTo().second != -1) {
    //     board.movePiece(move);
    //     return 1;
    // }
    
    // return 0;
}

// for evading next move captures
// board pass by value??? copy operator??
int ComputerPlayer3::simulate(BoardState board, Move m) {
    board.movePiece(m);
    vector<Piece*> pieces;
    if (isWhite) {
        pieces = board.whitePieces;
    } else {
        pieces = board.blackPieces;
    }

    int minvalue = 9999;

    for (Piece* p : pieces) {
        vector<Move> moves = p->validMoves; // get valid moves from piece
        for (Move m : moves) {
            pair<int, int> to = m.getTo();
            if (board.board[to.first][to.second] != nullptr) {
                int score = abs(board.board[to.first][to.second]->getValue());
                minvalue = fmin(score, minvalue);
            }
        }
    }

    return minvalue;
}
