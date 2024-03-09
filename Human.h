#include <iostream>
#include "Player.h"
#include "Move.h"

using namespace std;

#ifndef HUMAN_H
#define HUMAN_H

class Human : public Player{
    private:
        std::string name;
    public:
        Human();   
        Human(std::string name);
        std::string getName() override;
        Move* makeMove() override;
        ~Human();   
};

#endif