#include "Scissors.h"
#include "Move.h"

Scissors::Scissors(){
        setMove("Scissors");
        weak_against = { "Rock"};
        strong_against = { "Paper" };
        draw_against = { "Scissors" };
    }