#include "Sort.h"

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

class BubbleSort : public Sort {
    private:
    public:
        std::vector<int> sort(const std::vector<int>& list) override;
};

#endif