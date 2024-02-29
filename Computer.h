#include <iostream>
#include "Player.h"

#ifndef COMPUTER_H
#define COMPUTER_H

class Computer : public Player{
    public:
        char makeMove() override;
        std::string getName() override;   
};

#endif