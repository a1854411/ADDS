#include <string>
#include <vector>

#include <string>
#include "Move.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player{
    private:
        std::string name;
    public:
        virtual Move* makeMove() = 0;
        virtual std::string getName();
        virtual  void setName(std::string name); 
};

#endif