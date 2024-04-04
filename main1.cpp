#include <iostream>
#include "BubbleSort.h"

int main(){
    std::vector<int> unsorted_array = {3,5,2,6,1,8};

    BubbleSort bubble;
    std::vector<int> sorted_array = bubble.sort(unsorted_array);

    return 0;
}