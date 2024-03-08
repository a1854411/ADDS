#include <string>
#include <vector>
#include "Moves.h"
using namespace std;

#ifndef PIRATE_H
#define PIRATE_H

class Pirate : public Moves {
    public:
    Pirate(){
        setMove("Pirate");
        weak_against = { "Ninja", "Zombie"};
        strong_against = { "Monkey", "Robot" };
        draw_against = { "Pirate" };
    }
    ~Pirate();   
};

#endif