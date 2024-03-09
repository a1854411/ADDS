#include "Scissors.h"
#include "Moves.h"

Scissors::Scissors(){
        setMove("Scissors");
        weak_against = { "Rock"};
        strong_against = { "Paper" };
        draw_against = { "Scissors" };
    }