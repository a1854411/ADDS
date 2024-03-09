#include <iostream>
#include <string>
#include "Human.h"
#include "Move.h"
#include "Factory.h"

using namespace std;

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
    cout << "Enter move:";
    cin >> move;
    return (new Factory())->move_obj(move);
}