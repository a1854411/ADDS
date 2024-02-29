#include <iostream>
#include "Human.h"

Human::Human(std::string name) {
    // Initialize member variable with the provided name
    this->name = name;
}

std::string Human::getName(){
    return name;
} 

char Human::makeMove(){
    char move;
    std::cout << "Enter move:";
    std::cin >> move;
    return move;
}