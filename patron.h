#ifndef PATRON_H
#define PATRON_H

#include <iostream>
#include <string>

class patron {
    private:
        int patronID;
    public:
        int getID();
        void setID(int id);
        patron();
        patron(int id);
};

#endif