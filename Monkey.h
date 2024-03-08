#include <string>
#include <vector>
#include "Moves.h"
using namespace std;

#ifndef MONKEY_H
#define MONKEY_H   

class Monkey : public Moves {
    public:
    Monkey(){
        setMove("Monkey");
        weak_against = { "Pirate", "Zombie"};
        strong_against = { "Robot", "Ninja" };
        draw_against = { "Monkey" };
    }
   
    ~Monkey();   
};

#endif 