#ifndef BOARDSTATE_H
#define BOARDSTATE_H

#include <vector>
#include <memory>
#include "Move.h"
#include "pieces/Piece.h"

class KingPiece;

class Piece;

class Move;

class BoardState {
public:
    bool isWhiteTurn;

    // Source of truth for pieces, full ownership and responsible for deletion
    std::vector<std::unique_ptr<Piece>> whitePieces;
    std::vector<std::unique_ptr<Piece>> blackPieces;

    // Does not own the pieces, only stores pointers
    std::vector<std::vector<Piece*>> board;

    // Does not own the king pieces, only stores pointers
    KingPiece* whiteKing;
    KingPiece* blackKing;

    // Stack of moves, used for undoing
    std::vector<Move> lastMoves;

public:
    // Default constructor, initializes the board and sets it to white's turn
    BoardState();

    // Do not allow copying
    BoardState(const BoardState& other) = delete;

    // Gets whether there is a checkmate for the given color
    // Will call updateValidMoves() and getCheck() to determine this
    bool getCheckmate(bool white);

    // Returns KingPiece.checked for the current king
    // Does not update KingPiece.checked
    bool getCheck(bool white);

    // Gets whether pieces are attacking the king
    // Will update KingPiece.checked
    bool updateCheck(bool white);

    // Gets whether pieces are attacking the given location. If white == true we are seeing if there 
    // are black pieces which attack this tile
    bool getAttacked(int x, int y, bool white);

    // Updates the validMoves vectors with the valid moves for the current color
    // Will call Piece::getPieceMoves(board) which returns a vector of moves
    void updateValidMoves();

    // Returns whether the given player has no valid moves
    bool getStalemate(bool white);

    // Moves the piece with the given move
    bool movePiece(const Move& move);

    //moves piece only if it is a legal move
    bool movePieceIfLegal(const Move& move);

    // Sets the piece at the given location
    void setPiece(std::unique_ptr<Piece>&& piece, int x, int y);

    // Removes the piece at the given location
    void removePiece(int x, int y);

    // Undoes the last move
    void undo();

    // Returns whether the conditions are met
    // so the game can start
    bool canStartGame();

    // Returns all valid moves for the current player
    // Concatenates all validMoves vectors for the current player
    std::vector<Move> allValidMoves() const;

    // Makes a piece based on the given character
    static std::unique_ptr<Piece> makePiece(char piece, int y, int x);
};

#endif 
