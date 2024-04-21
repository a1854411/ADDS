#include "Sort.h"

#ifndef QUICKSORT_H
#define QUICKSORT_H

class QuickSort : public Sort {
    private:
        void swap(int& a, int& b);
        int partition(std::vector<int>& list, int low, int high);
        void sortHelper(std::vector<int>& list, int low, int high);
    public:
        std::vector<int> sort(const std::vector<int>& list) override;
};

#endif