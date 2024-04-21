#ifndef SORT_H
#define SORT_H

#include <vector>
#include <iostream>

class Sort {
    private:
    public:
        virtual std::vector<int> sort(const std::vector<int>& list) = 0;
};

#endif