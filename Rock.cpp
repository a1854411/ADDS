#include "Rock.h"
#include "Move.h"

Rock::Rock(){
        setMove("Rock");
        weak_against = { "Paper"};
        strong_against = { "Scissors" };
        draw_against = { "Rock" };
    }