#include "Pirate.h"
#include "Moves.h"

Pirate::Pirate(){
        setMove("Pirate");
        weak_against = { "Ninja", "Zombie"};
        strong_against = { "Monkey", "Robot" };
        draw_against = { "Pirate" };
    }