#include <string>
#include <vector>
#include <cstdio>

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
    printf("Enter move:");
    char buffer[100];
    scanf("%s", buffer);
    move = std::string(buffer);
    return (new Factory())->move_obj(move);
}