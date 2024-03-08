#include <string>
#include <vector>
#include "Moves.h"
using namespace std;

#ifndef NINJA_H
#define NINJA_H

class Ninja : public Moves {
    public:
    Ninja(){
        setMove("Ninja");
        weak_against = { "Monkey", "Robot"};
        strong_against = { "Zombie", "Pirate" };
        draw_against = { "Ninja" };
    }
   
    ~Ninja();   
};

#endif