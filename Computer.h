#include <string>
#include <vector>
#include "Player.h"

#ifndef COMPUTER_H
#define COMPUTER_H

class Computer : public Player{
    public:
        Move* makeMove() override;
        std::string getName() override;   
};

#endif