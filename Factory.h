#include <string>
#include <vector>
#include "Moves.h"
#include "Referee.h"
#include "Player.h"
#include "Human.h"
using namespace std;

#ifndef FACTORY_H
#define FACTORY_H

class Factory {
    Moves* getMove(std::string move){
        if (move == "Rock") {
            Moves* newRock;
            return newRock;
        }
        if (move == "Scissors") {
            Moves* newScissors;
            return newScissors;
        }
        if (move == "Paper") {
            Moves* newPaper;
            return newPaper;
        }
        if (move == "Ninja") {
            Moves* newNinja;
            return newNinja;
        }
        if (move == "Zombie") {
            Moves* newZombie;
            return newZombie;
        }
        if (move == "Monkey") {
            Moves* newMonkey;
            return newMonkey;
        }
        if (move == "Pirate") {
            Moves* newPirate;
            return newPirate;
        }
        if (move == "Robot") {
            Moves* newRobot;
            return newRobot;
        }
    }
};


#endif FACTORY_H