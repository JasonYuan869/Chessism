#ifndef TERMINAL_H 
#define TERMINAL_H

#include "Observer.h"
#include "Game.h"

class Terminal : public Observer {
    Game* game; 
    public: 
        Terminal();
        ~Terminal();
        void printBoard();
};

#endif
