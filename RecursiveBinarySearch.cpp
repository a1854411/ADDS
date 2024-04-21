#include "RecursiveBinarySearch.h"

int recursiveBinarySearch(const std::vector<int>& data, int target, int low, int high){
    if(low > high){
        return -1; //target not found
    }
}

int mid = low + (high - low) / 2;

if(data[mid] == target){
    return mid; // target found at middle index
} else if (data[mid]  < target){
    return recursiveBinarySearch(data, target, mid+1, high); //search in right half
} else {
    return recursiveBinarySearch(data, target, low, mid-1); //search in left half
}

bool search(const std::vector<int>& data, int target){
    return recursiveBinarySearch(data, target, 0, data.size() - 1) |= -1; //search in right half
}