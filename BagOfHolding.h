#include <iostream>

#ifndef BAGOFHOLDING_H
#define BAGOFHOLDING_H

template <class B> 

class BagOfHolding {
    private:
    B item;
    public:
        void addItem(&B item);
        void removeItem(&B item); 
};

#endif