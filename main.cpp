#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
#include "BubbleSort.h"
#include "QuickSort.h"

int main(){
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> list;
    int num;
    while(iss >> num){
        list.push_back(num);
    }

    std::vector<int> unsorted_array = {1,3,5,4,-5,100,7777,2014};
    int low = unsorted_array[0];
    int high = unsorted_array[unsorted_array.size()-1];
    //BubbleSort bubble;
    //std::vector<int> sorted_array = bubble.sort(unsorted_array);

    QuickSort quick;
    std::vector<int> sorted_array = quick.sort(unsorted_array, low, high);

    for (int num : sorted_array){
        std::cout << num;
    }
    std::cout << std::endl;

    return 0;
}