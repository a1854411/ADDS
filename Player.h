#include <iostream>
#include <string>
#include "Moves.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player{
    private:
        std::string name;
    public:
        virtual Moves* makeMove();
        virtual std::string getName();
        virtual  void setName(std::string name);
    
};


#endif