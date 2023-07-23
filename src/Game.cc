#include "Game.h"
#include "Piece.h"
#include "PawnPiece.h"
#include "RookPiece.h"
#include "KnightPiece.h"
#include "BishopPiece.h"
#include "QueenPiece.h"
#include "KingPiece.h"

#include <stdio>
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
        switch (command) {
            case "+":
                cin >> piece >> location[0] >> location[1];
                x = location[0] - 'a';
                y = location[1] - '1';
                newPiece = Piece::makePiece(piece, x, y);
                board.setPiece(newPiece, x, y);
                notifyObservers();
                break;
            case "-":
                cin >> piece >> location[0] >> location[1];
                x = location[0] - 'a';
                y = location[1] - '1';
                board.removePiece(x, y);
                notifyObservers();
                break;
            case "=":
                cin >> command;
                if (command == "white") {
                    isWhiteTurn = true;
                } else if (command == "black") {
                    isWhiteTurn = false;
                }
                break;
            case "done":
                if (board.canStartGame()) {
                    return;
                } else {
                    cout << "Invalid board setup" << endl;
                }
                break;
            default:
                continue;
        }
    }

}

BoardState& Game::getBoard() {
    return board;
}
