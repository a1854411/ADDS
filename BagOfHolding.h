#include <iostream>
#include <vector>

#ifndef BAGOFHOLDING_H
#define BAGOFHOLDING_H

template <class B> 

class BagOfHolding {
    private:
        std::vector<B>; 
    public:
        void addItem(B item);
        void removeItem(B item); 
};

#endif