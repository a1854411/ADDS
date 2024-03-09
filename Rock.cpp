#include "Rock.h"
#include "Moves.h"

Rock::Rock(){
        setMove("Rock");
        weak_against = { "Paper"};
        strong_against = { "Scissors" };
        draw_against = { "Rock" };
    }