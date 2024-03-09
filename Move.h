#include <string>
#include <vector>
using namespace std;

#ifndef MOVES_H
#define MOVES_H

class Move {
    private:
    std::string move;
   
    public:
    std::string getMove();
    void setMove(std::string chosen_move);

    std::vector<std::string> weak_against;
    std::vector<std::string> strong_against;
    std::vector<std::string> draw_against;

    bool willLoseAgainst(Move* move);
    bool willWinAgainst(Move* move);
    bool willDrawAgainst(Move* move);
};

#endif