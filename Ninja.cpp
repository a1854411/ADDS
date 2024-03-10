#include <string>
#include <vector>

#include "Ninja.h"
#include "Move.h"

Ninja::Ninja(){
        setMove("Ninja");
        weak_against = { "Monkey", "Robot"};
        strong_against = { "Zombie", "Pirate" };
        draw_against = { "Ninja" };
    }