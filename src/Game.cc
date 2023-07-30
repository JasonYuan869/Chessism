#include "Game.h"
#include "pieces/Piece.h"
#include "pieces/KingPiece.h"

#include <iostream>
#include <string>
using namespace std;

Game::Game(Player* whitePlayer, Player* blackPlayer) :  board{true}, white{whitePlayer}, black{blackPlayer} {}

Game::~Game() {
    delete white;
    delete black;
}

void Game::setup() {
    cout << "Enter setup commands" << endl;
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
            if (x < 0 || x > 7 || y < 0 || y > 7) {
                cout << "Invalid location" << endl;
                continue;
            }
            newPiece = BoardState::makePiece(piece, x, y);
            board.setPiece(newPiece, x, y);
            notifyObservers();
        } else if (command == "-") {
            cin >> location[0] >> location[1];
            x = location[0] - 'a';
            y = location[1] - '1';
            if (x < 0 || x > 7 || y < 0 || y > 7) {
                cout << "Invalid location" << endl;
                continue;
            }
            board.removePiece(x, y);
            notifyObservers();
        } else if (command == "=") {
            cin >> command;
            if (command == "white") {
                board.isWhiteTurn = true;
            } else if (command == "black") {
                board.isWhiteTurn = false;
            } else {
                cout << "Invalid colour" << endl;
                continue;
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
    // Print the board
    notifyObservers();

    while (true) {
        Player* currentPlayer = board.isWhiteTurn ? white : black;
        string colour = board.isWhiteTurn ? "White" : "Black";
        
        
        if (board.getCheckmate(board.isWhiteTurn)) {
            // Checkmate
            return board.isWhiteTurn ? 1 : 0;
        }

        // Is the player in check?
        if (board.getCheck(board.isWhiteTurn)) {
            // Check if there is a checkmate for this player
          
            cout << colour << " is in check." << endl;
        }

        MoveResult moveResult = currentPlayer->makeMove(board);
        switch (moveResult) {
            case INVALID_MOVE:
                continue;
            case SUCCESS:
                notifyObservers();
                break;
            case STALEMATE:
                return 0.5;
            case RESIGNED:
                return board.isWhiteTurn ? 1 : 0;
            case SETUP:
                // Setup mode, only if game hasn't started
                if (board.lastMoves.empty()) {
                    setup();
                    continue;
                } else {
                    cout << "Cannot enter setup mode after game has started" << endl;
                    continue;
                }
        }
    }
}
