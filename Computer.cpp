#include <string>
#include <vector>
#include "Computer.h"
#include "Factory.h"

std::string Computer::getName(){
    return "Computer";
} 

Move* Computer::makeMove(){
    return (new Factory())->move_obj("Rock");
}