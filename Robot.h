#include <string>
#include <vector>
#include "Moves.h"
using namespace std;

#ifndef ROBOT_H
#define ROBOT_H

class Robot : public Moves {
    public:
    Robot(){
        setMove("Robot");
        weak_against = { "Pirate", "Monkey"};
        strong_against = { "Zombie", "Ninja" };
        draw_against = { "Robot" };
    }
   
    ~Robot();   
};

#endif