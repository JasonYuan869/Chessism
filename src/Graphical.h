#ifndef GRAPHICAL_H 
#define GRAPHICAL_H

#include "Observer.h"
#include "Game.h"

class Graphical : public Observer {
    Game* game; 
    public: 
        Graphical();
        ~Graphical();
        void printBoard();
};

#endif
