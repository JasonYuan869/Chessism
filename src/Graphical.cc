#include "Graphical.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <string>
#include <unistd.h>
#include "PiecePixels.h"

using namespace std;

Graphical::Graphical(Game *game) : game{game}, colours{0} {
    game->attach(this);

    d = XOpenDisplay(nullptr);
    if (d == nullptr) {
        cerr << "Cannot open display" << endl;
        exit(1);
    }

    int s = DefaultScreen(d);
    w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, WINDOW_SIZE, WINDOW_SIZE, 1,
                            BlackPixel(d, s), WhitePixel(d, s));

    XSelectInput(d, w, ExposureMask | KeyPressMask);
    XMapWindow(d, w);

    Pixmap pix = XCreatePixmap(d, w, WINDOW_SIZE,
                               WINDOW_SIZE, DefaultDepth(d, DefaultScreen(d)));
    gc = XCreateGC(d, pix, 0, (XGCValues *) nullptr);

    XFlush(d);
    XFlush(d);

    // Set up colours.
    XColor xcolour;
    Colormap cmap;
    char color_vals[4][11] = {"white", "black", "sienna", "peach puff"};

    cmap = DefaultColormap(d, DefaultScreen(d));
    for (int i = 0; i < 4; ++i) {
        XParseColor(d, cmap, color_vals[i], &xcolour);
        XAllocColor(d, cmap, &xcolour);
        colours[i] = xcolour.pixel;
    }

    // Make window non-resizeable.
    XSizeHints hints;
    hints.flags = (USPosition | PSize | PMinSize | PMaxSize);
    hints.height = hints.base_height = hints.min_height = hints.max_height = WINDOW_SIZE;
    hints.width = hints.base_width = hints.min_width = hints.max_width = WINDOW_SIZE;
    XSetNormalHints(d, w, &hints);

    XSynchronize(d, True);

    usleep(1000);
    draw();
}

Graphical::~Graphical() {
    XFreeGC(d, gc);
    XDestroyWindow(d, w);
    XCloseDisplay(d);
}

void Graphical::notify() {
    draw();
}

void Graphical::draw() {
    drawBoard();

    BoardState& board = game->getBoard();
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece *piece = board.board[i][j];
            if (piece != nullptr) {
                drawPiece(piece);
            }
        }
    }
}

void Graphical::drawBoard() {
    // Fill background
    fillRectangle(0, 0, 512, 512, Sienna);

    // Draw board
    int size = WINDOW_SIZE / 8;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            fillRectangle((j * 2 + (i % 2)) * size, i * size, size, size, PeachPuff);
        }
    }
}

void Graphical::drawPiece(Piece *piece) {
    int x = piece->position_x * WINDOW_SIZE / 8;
    int y = (WINDOW_SIZE - (piece->position_y * WINDOW_SIZE / 8 + WINDOW_SIZE / 8));
    switch (piece->getType()) {
        case PAWN:
            drawPixels(x, y,piece->isWhite ? wp : bp);
            break;
        case ROOK:
            drawPixels(x, y,piece->isWhite ? wr : br);
            break;
        case KNIGHT:
            drawPixels(x, y, piece->isWhite ? wn : bn);
            break;
        case BISHOP:
            drawPixels(x, y,piece->isWhite ? wb : bb);
            break;
        case QUEEN:
            drawPixels(x, y, piece->isWhite ? wq : bq);
            break;
        case KING:
            drawPixels(x, y, piece->isWhite ? wk : bk);
            break;
    }
}

void Graphical::drawPixels(int x, int y, const char* data) {
    for (int i = 0; i < 64 * 64; i++) {
        if (data[i] == 0) {
            continue;
        }
        XSetForeground(d, gc, data[i] == 1 ? colours[White] : colours[Black]);
        int pixelX = x + i % 64;
        int pixelY = y + i / 64;
        XDrawPoint(d, w, gc, pixelX, pixelY);
    }
}

void Graphical::fillRectangle(int x, int y, int width, int height, int colour) {
    XSetForeground(d, gc, colours[colour]);
    XFillRectangle(d, w, gc, x, y, width, height);
}

