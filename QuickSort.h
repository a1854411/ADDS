#include "Sort.h"

#ifndef QUICKSORT_H
#define QUICKSORT_H

class QuickSort : public Sort {
    private:
    public:
        std::vector<int> sort(std::vector<int> list, int high, int low);
};

#endif