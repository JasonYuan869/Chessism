#include "Player.h"
using namespace std;

Player::Player(bool isWhite) : isWhite{isWhite} {}

Player::~Player() {}

vector<Move> Player::allValidMoves(BoardState &board) {
    vector<Piece*>& pieces = isWhite ? board.whitePieces : board.blackPieces;
    vector<Move> moves;
    for (auto& piece : pieces) {
        moves.insert(moves.end(), piece->validMoves.begin(), piece->validMoves.end());
    }
    return moves;
}

