#ifndef TERMINAL_H 
#define TERMINAL_H

#include "Observer.h"
#include "Game.h"

class Terminal : public Observer {
    Game* game; 
    public: 
        explicit Terminal(Game* game);
        ~Terminal() override;
        void notify() override;
};

#endif
