#include <string>
#include <vector>
#include <iostream>

using namespace std;

#include "Human.h"
#include "Move.h"
#include "Factory.h"

Human::Human(){
    this->name = "Human";
}

Human::Human(std::string inputname) {
    this->name = inputname;
}

std::string Human::getName(){
    return name;
}  

Move* Human::makeMove(){
    std::string move;           
    std::cout << "Enter move:";
    std::cin >> move;
    return (new Factory())->move_obj(move);
}