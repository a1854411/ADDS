#include <string>
#include <vector>
#include "Moves.h"

std::string Moves::getMove(){
        return move;
    }

void Moves::setMove(std::string chosen_move){
        this->move = chosen_move;
    }

bool Moves::willLooseAgainst(Moves* move){
    for (int i=0; i<weak_against.size(); i++){
        if(move->getMove() == weak_against[i]){
            return true;
        }
    }
    return false;
}

bool Moves::willWinAgainst(Moves* move){
    for (int i=0; i<strong_against.size(); i++){
        if(move->getMove() == strong_against[i]){
            return true;
        }
    }
    return false;
}

bool Moves::willDrawAgainst(Moves* move){
    for (int i=0; i<draw_against.size(); i++){
        if(move->getMove() == draw_against[i]){
            return true;
        }
    }
    return false;
}
