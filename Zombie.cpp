#include <string>
#include <vector>
#include "Moves.h"
#include "Zombie.h"
using namespace std;

Zombie::Zombie(){
        setMove("Zombie");
        weak_against = { "Ninja", "Robot"};
        strong_against = { "Pirate", "Monkey" };
        draw_against = { "Zombie" };
    }