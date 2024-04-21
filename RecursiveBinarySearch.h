#ifndef RECURSIVEBINARYSEARCH_H
#define RECURSIVEBINARYSEARCH_H

#include <vector>

class RecursiveBinarySearch {
public:
    bool search(const std::vector<int>& list, int target);
private:
    bool binarySearch(const std::vector<int>& list, int target, int low, int high);
};

#endif