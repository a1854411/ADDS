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

    if (winner == nullptr){
        std::cout << "Its a tie" << std::endl;
        return 0;
    }

    std::cout << winner->getName() << " wins" << std::endl;
}