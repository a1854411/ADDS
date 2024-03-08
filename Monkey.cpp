#include <string>
#include <vector>
#include "Moves.h"
#include "Monkey.h"
using namespace std;

Monkey::Monkey(){
        setMove("Monkey");
        weak_against = { "Pirate", "Zombie"};
        strong_against = { "Robot", "Ninja" };
        draw_against = { "Monkey" };
    }