 #ifndef CHESSISM_GRAPHICALTILE_H
 #define CHESSISM_GRAPHICALTILE_H

 #include "Graphical.h"

 class GraphicalTile {
     int x, y;
     PieceType pieceType;
     bool white;
     Graphical *parent;

 public:
     GraphicalTile(int x, int y, PieceType pieceType, bool white, Graphical* parent);

     void draw();

     void update(PieceType pieceType, bool white);
 };


 #endif //CHESSISM_GRAPHICALTILE_H
