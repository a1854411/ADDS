#include <string>
#include <vector>
#include "Moves.h"
using namespace std;

#ifndef ZOMBIE_H
#define  ZOMBIE_H

class Zombie : public Moves {
    public:
    Zombie(){
        setMove("Zombie");
        weak_against = { "Ninja", "Robot"};
        strong_against = { "Pirate", "Monkey" };
        draw_against = { "Zombie" };
    }
   
    ~Zombie();   
};

#endif