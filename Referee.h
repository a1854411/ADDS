#include <string>
#include <vector>
#include "Player.h"
#include "Move.h"

#ifndef REFEREE_H
#define REFEREE_H

class Referee{
    public:
        Referee();
        Player * refGame(Player * player1, Player * player2);
};

#endif