// #ifndef GRAPHICAL_H
// #define GRAPHICAL_H

// #include <X11/Xlib.h>
// #include "Observer.h"
// #include "Game.h"

// #define TILE_SIZE 64
// #define WINDOW_SIZE (TILE_SIZE * 8)

// class GraphicalTile;

// class Graphical : public Observer {
//     Game *game;
//     Display *d;
//     Window w;
//     GC gc;
//     unsigned long colours[10];
//     GraphicalTile *tiles[64];

// public:
//     explicit Graphical(Game *game);
//     ~Graphical() override;

//     void notify() override;
//     enum {White=0, Black, Sienna, PeachPuff};

//     void updateTiles();
//     void fillRectangle(int x, int y, int width, int height, int colour);
//     void drawPixels(int x, int y, const char *data);

//     void drawBoard();
// };

// #endif
