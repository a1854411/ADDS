#include <string>
#include <vector>
#include "Move.h"
#include "Referee.h"
#include "Player.h"
#include "Human.h"
using namespace std;

#ifndef FACTORY_H
#define FACTORY_H

class Factory {
    public:
        Move* move_obj(std::string move);
};

#endif