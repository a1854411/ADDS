#include <string>
#include <vector>

#include "Referee.h"
#include "Human.h"
#include "Computer.h"
#include "Player.h"
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