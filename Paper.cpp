#include "Paper.h"
#include "Move.h"

Paper::Paper(){
        setMove("Paper");
        weak_against = { "Scissors"};
        strong_against = { "Rock" };
        draw_against = { "Paper" };
    }