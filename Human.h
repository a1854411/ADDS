#include <iostream>
#include "Player.h"

#ifndef HUMAN_H
#define HUMAN_H

class Human : public Player{
    private:
        std::string name;
    public:
        Human(std::string name);
        char makeMove() override;
        std::string getName() override;   
};

#endif