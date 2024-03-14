#include <string>
#include <vector>
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
<<<<<<< HEAD
        std::string getName() override;
        Move* makeMove() override;  
=======
        char makeMove();
        std::string getName();   
>>>>>>> 8ddea2194e7a7094dc7a25bf0675058eb866ac1b
};

#endif