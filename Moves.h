#include <string>
#include <vector>
using namespace std;

#ifndef MOVES_H
#define MOVES_H

class Moves {
    private:
    std::string move;
   
    public:
    std::string getMove();
    void setMove(std::string specific_move);

    std::vector<std::string> weak_against;
    std::vector<std::string> strong_against;
    std::vector<std::string> draw_against;
};

#endif