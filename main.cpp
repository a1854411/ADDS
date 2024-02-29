#include <iostream>
#include "Referee.h"
#include "Human.h"
#include "Computer.h"

int main (){

    Human *human;
    human = new Human("Mei");
    
    Computer *Mac;
    Mac= new Computer;

    Referee ump;

    Player* winner = ump.refGame(human,Mac);

    std::cout << winner->getName() << "wins";
}