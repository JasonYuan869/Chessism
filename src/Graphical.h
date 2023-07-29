#ifndef GRAPHICAL_H
#define GRAPHICAL_H

#include <X11/Xlib.h>
#include "Observer.h"
#include "Game.h"

class Graphical : public Observer {
    Game *game;
    Display *d;
    Window w;
    GC gc;
    unsigned long colours[10];

public:
    explicit Graphical(Game *game);
    ~Graphical() override;

    void notify() override;
    enum {White=0, Black, Sienna, PeachPuff};

    void drawBoard();
    void drawPiece(Piece* piece);
    void fillRectangle(int x, int y, int width, int height, int colour);
    void drawPixels(int x, int y, const char *data);

    void draw();
};

#endif
