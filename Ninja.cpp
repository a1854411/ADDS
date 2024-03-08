#include "Ninja.h"
#include "Moves.h"

Ninja::Ninja(){
        setMove("Ninja");
        weak_against = { "Monkey", "Robot"};
        strong_against = { "Zombie", "Pirate" };
        draw_against = { "Ninja" };
    }