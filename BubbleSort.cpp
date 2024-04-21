#include "BubbleSort.h"
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

std::vector<int> BubbleSort::sort(const std::vector<int>& list) {
    std::vector<int> sortedList = list;
    for (int i = sortedList.size() - 1; i > 1; i--) {
        for (int j = 0; j < i; j++) {
            if (sortedList[j] > sortedList[j + 1]) {
                swap(sortedList[j], sortedList[j + 1]);
            }
        }
    }
    return sortedList;
}