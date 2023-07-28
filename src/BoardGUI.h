#ifndef CHESSISM_BOARDGUI_H
#define CHESSISM_BOARDGUI_H

#include <gdkmm/pixbuf.h>
#include <vector>
#include "Piece.h"

class BoardGUI {
    // black pieces
    std::vector<Glib::RefPtr<Gdk::Pixbuf>> blackPieces;

    // white pieces
    std::vector<Glib::RefPtr<Gdk::Pixbuf>> whitePieces;

    Glib::RefPtr<Gdk::Pixbuf> boardImage;
public:
    BoardGUI();
    ~BoardGUI();

    // Returns the 60x60 image of the piece
    Glib::RefPtr<Gdk::Pixbuf> image(Piece* piece);

    // Returns the 480x480 image of the board
    Glib::RefPtr<Gdk::Pixbuf> board();
};


#endif //CHESSISM_BOARDGUI_H
