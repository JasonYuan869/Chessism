//
// Created by jason on 2023-07-29.
//

#include "GraphicalTile.h"
#include "PiecePixels.h"

GraphicalTile::GraphicalTile(int x, int y, int pieceType, bool white, Graphical* parent) : x{x}, y{y}, pieceType{pieceType}, white{white}, parent{parent} {}



void GraphicalTile::draw() {
    int tileColour = (x + y) % 2 == 0 ? Graphical::Sienna : Graphical::PeachPuff;

    int pixelX = x * TILE_SIZE;
    int pixelY = WINDOW_SIZE - (y+1) * TILE_SIZE;

    parent->fillRectangle(pixelX, pixelY, TILE_SIZE, TILE_SIZE, tileColour);

    switch (pieceType) {
        case PieceType::PAWN:
            parent->drawPixels(pixelX, pixelY, white ? wp : bp);
            break;
        case PieceType::ROOK:
            parent->drawPixels(pixelX, pixelY, white ? wr : br);
            break;
        case PieceType::KNIGHT:
            parent->drawPixels(pixelX, pixelY, white ? wn : bn);
            break;
        case PieceType::BISHOP:
            parent->drawPixels(pixelX, pixelY, white ? wb : bb);
            break;
        case PieceType::QUEEN:
            parent->drawPixels(pixelX, pixelY, white ? wq : bq);
            break;
        case PieceType::KING:
            parent->drawPixels(pixelX, pixelY, white ? wk : bk);
            break;
        default:
            break;
    }
}

void GraphicalTile::update(int pieceType, bool white) {
    bool changed = false;
    if (this->pieceType != pieceType) {
        this->pieceType = pieceType;
        changed = true;
    }
    if (this->white != white) {
        this->white = white;
        changed = true;
    }
    if (changed) {
        draw();
    }
}
