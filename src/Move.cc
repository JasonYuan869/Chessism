#include "Move.h"


Move::Move(int to_x,int to_y, int from_x,int from_y,char promotion = '-' ) : to{to_x,to_y}, from{from_x,from_y}, promotion{promotion}{}

Move::~Move() {
    
}
