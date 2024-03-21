#include <iostream>
#include <vector>

#ifndef BAGOFHOLDING_H
#define BAGOFHOLDING_H

class BagOfHolding {
    private:
        std::vector<std::string> bag; 
    public:
        void addItem(std::string item);
        std::string removeItem(); 
        std::string removeItem(std::string item); 
};

#endif