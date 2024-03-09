#include <string>
#include <vector>
#include "Move.h"

std::string Move::getMove(){
        return move;
    }

void Move::setMove(std::string chosen_move){
        this->move = chosen_move;
    }

bool Move::willLoseAgainst(Move* move){
    for (decltype(strong_against.size()) i=0; i < weak_against.size(); i++){
        if(move->getMove() == weak_against[i]){
            return true;
        }
    }
    return false;
}

bool Move::willWinAgainst(Move* move){
    for (decltype(strong_against.size()) i=0; i < strong_against.size(); i++){
        if(move->getMove() == strong_against[i]){
            return true;
        }
    }
    return false;
}

bool Move::willDrawAgainst(Move* move){
    for (decltype(strong_against.size()) i=0; i < draw_against.size(); i++){
        if(move->getMove() == draw_against[i]){
            return true;
        }
    }
    return false;
}
