#include <string>
#include <vector>
#include "Move.h"
#include "Robot.h"
using namespace std;

Robot::Robot(){
        setMove("Robot");
        weak_against = { "Pirate", "Monkey"};
        strong_against = { "Zombie", "Ninja" };
        draw_against = { "Robot" };
    }