// #include "RecursiveBinarySearch.h"

// int recursiveBinarySearch(const std::vector<int>& data, int target, int low, int high){
//     if(low > high){
//         return -1; //target not found
//     }

//     int mid = low + (high - low) / 2;

//     if(data[mid] == target){
//         return mid; // target found at middle index
//     } else if (data[mid]  < target){
//         return recursiveBinarySearch(data, target, mid+1, high); //search in right half
//     } else {
//         return recursiveBinarySearch(data, target, low, mid-1); //search in left half
//     }
// }

// bool search(const std::vector<int>& data, int target){
//     return recursiveBinarySearch(data, target, 0, data.size() - 1) != -1; //search in right half
// }

#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(const std::vector<int>& list, int target) {
    return binarySearch(list, target, 0, list.size() - 1);
}

bool RecursiveBinarySearch::binarySearch(const std::vector<int>& list, int target, int low, int high) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (list[mid] == target) {
            return true;
        } else if (list[mid] < target) {
            return binarySearch(list, target, mid + 1, high);
        } else {
            return binarySearch(list, target, low, mid - 1);
        }
    }
    return false;
}