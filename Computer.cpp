#include <iostream>
#include "Computer.h"


std::string Computer::getName(){
    return "Computer";
} 

Moves* Computer::makeMove(){
    return (new Factory())->getMove("Rock");
}