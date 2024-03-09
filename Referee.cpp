#include <string>
#include <vector>

#include "Referee.h"
#include "Move.h"
#include "Player.h"
#include "Factory.h"
#include "Rock.h"
#include "Scissors.h"
#include "Paper.h"
#include "Pirate.h"
#include "Ninja.h"
#include "Monkey.h"
#include "Zombie.h"
#include "Robot.h"

Referee::Referee(){}

Player * Referee::refGame(Player * player1, Player * player2){
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();


    if(move1->willWinAgainst(move2)){
        return player1;
    }
    if(move1->willLoseAgainst(move2)){
        return player2;
    }
    if(move1->willDrawAgainst(move2)){
        return nullptr;
    }
    else{return nullptr;}
}