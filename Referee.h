#include <iostream>
#include "Player.h"

#ifndef REFEREE_H
#define REFEREE_H

#include <iostream>

class Referee{
    public:
        Referee();
        Player * refGame(Player * player1, Player * player2);
};

#endif