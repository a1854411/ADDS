#include <string>
#include <vector>

#include "Factory.h"
#include "Move.h"
#include "Rock.h"
#include "Scissors.h"
#include "Paper.h"
#include "Pirate.h"
#include "Ninja.h"
#include "Monkey.h"
#include "Zombie.h"
#include "Robot.h"

Move* Factory::move_obj(std::string move){
        if (move == "Rock") {
            return new Rock;
        }
        if (move == "Scissors") {
            return new Scissors;
        }
        if (move == "Paper") {
            return new Paper;
        }
        if (move == "Ninja") {
            return new Ninja;
        }
        if (move == "Zombie") {
            return new Zombie;
        }
        if (move == "Monkey") {
            return new Monkey;
        }
        if (move == "Pirate") {
            return new Pirate;
        }
        if (move == "Robot") {
            return new Robot;
        }
        else{return nullptr;}
    }