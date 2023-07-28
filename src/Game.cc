#include "Game.h"
#include "Piece.h"
#include "PawnPiece.h"
#include "RookPiece.h"
#include "KnightPiece.h"
#include "BishopPiece.h"
#include "QueenPiece.h"
#include "KingPiece.h"

#include <iostream>
#include <string>
using namespace std;

Game::Game(Player* whitePlayer, Player* blackPlayer) : white{whitePlayer}, black{blackPlayer}, isWhiteTurn{true} {}

Game::~Game() {
    delete white;
    delete black;
}

void Game::setup() {

    string command;
    char piece;
    char location[2];
    int x, y;
    Piece* newPiece;
    while (cin >> command) {
        if (command == "+") {
            cin >> piece >> location[0] >> location[1];
            x = location[0] - 'a';
            y = location[1] - '1';
            newPiece = BoardState::makePiece(piece, x, y);
            board.setPiece(newPiece, x, y);
            notifyObservers();
        } else if (command == "-") {
            cin >> piece >> location[0] >> location[1];
            x = location[0] - 'a';
            y = location[1] - '1';
            board.removePiece(x, y);
            notifyObservers();
        } else if (command == "=") {
            cin >> command;
            if (command == "white") {
                isWhiteTurn = true;
            } else if (command == "black") {
                isWhiteTurn = false;
            }
        } else if (command == "done") {
            if (board.canStartGame()) {
                return;
            } else {
                cout << "Invalid board setup" << endl;
            }
        } else {
            cout << "Invalid command" << endl;
        }
    }

    if (cin.eof()) {
        throw -1;
    }
}

BoardState& Game::getBoard() {
    return board;
}

double Game::run() {
    while (true) {
        Player* currentPlayer = isWhiteTurn ? white : black;
        string colour = isWhiteTurn ? "White" : "Black";

        // Is the player in check?
        if (board.getCheck(isWhiteTurn)) {
            // Check if there is a checkmate for this player
            if (board.getCheckmate(isWhiteTurn)) {
                // Checkmate
                return isWhiteTurn ? 1 : 0;
            }

            cout << colour << " is in check." << endl;
        }

        int moveResult = currentPlayer->makeMove(board);
        switch (moveResult) {
            case 0:
                // Successful move
                notifyObservers();
                break;
            case 1:
                // Invalid move, try again
                continue;
            case 2:
                // Stalemate, no valid moves
                return 0.5;
            case 3:
                // Player resigned
                return isWhiteTurn ? 1 : 0;
        }

        // Go to next player's turn
        isWhiteTurn = !isWhiteTurn;
    }
}
