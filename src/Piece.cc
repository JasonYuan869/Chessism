#include "Piece.h"

using namespace std;

bool Piece::withinBounds(int x,int y){
    return (x >= 0 && x < 8 && y >= 0 && y < 8); 
}