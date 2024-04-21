// #include "QuickSort.h"
// #include "Sort.h"
// void swap(int* a, int* b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int partition(std::vector<int>& data, int low, int high){
//     // choose the third element as the pivot (if list length list is at least 3)
//     int pivot_index = low + 2;
//     if(low + 2 <= high){
//         swap(&data[pivot_index], &data[high]);
//     }
//     pivot_index = high;

//     int pivot = data[pivot_index];
//     int i = low - 1;

//     for(int j=low; j<high; j++){
//         if(data[j] <= pivot){
//             i++;
//             swap(&data[i], &data[j]);
//         }
//     }

//     swap(&data[i+1], &data[pivot_index]);
//     return i + 1;
// }

// std::vector<int> sort(std::vector<int>& list, int high, int low){
//     if(low < high){
//         int pivot_index = partition(list, low, high);
//         sort(list, low, pivot_index - 1);
//         sort(list, pivot_index + 1, high);
//     }
//     return list;
// }

#include "QuickSort.h"

void QuickSort::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int QuickSort::partition(std::vector<int>& list, int low, int high) {
    int pivot = list[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (list[j] <= pivot) {
            ++i;
            swap(list[i], list[j]);
        }
    }
    swap(list[i + 1], list[high]);
    return i + 1;
}

std::vector<int> QuickSort::sort(const std::vector<int>& list) {
    std::vector<int> sortedList = list;
    int n = sortedList.size();
    sortHelper(sortedList, 0, n - 1);
    return sortedList;
}

void QuickSort::sortHelper(std::vector<int>& list, int low, int high) {
    if (low < high) {
        int pi = partition(list, low, high);
        sortHelper(list, low, pi - 1);
        sortHelper(list, pi + 1, high);
    }
}