#include <iostream>
#include <string>

#ifndef PLAYER_H
#define PLAYER_H

class Player{
    private:
        std::string name;
    public:
        virtual char makeMove( );
        virtual std::string getName( );
    
};


#endif