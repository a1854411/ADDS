#include <iostream>
#include "Human.h"

using namespace std;

Human::Human(){
    this->name = "Human";
}

Human::Human(std::string inputname) {
    // Initialize member variable with the provided name
    this->name = inputname;
}

std::string Human::getName(){
    return name;
} 

char Human::makeMove(){
    char move;
    cout << "Enter move:";
    cin >> move;
    return move;
}