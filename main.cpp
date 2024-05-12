// #include <iostream>
// #include <sstream>
// using namespace std;
// #include "BubbleSort.h"
// #include "QuickSort.h"

// int main(){
//     std::string line;
//     std::getline(std::cin, line);
//     std::istringstream iss(line);
//     std::vector<int> list;
//     int num;
//     while(iss >> num){
//         list.push_back(num);
//     }

//     std::vector<int> bubbleunsorted_array = {1,3,5,4,-5,100,7777,2014};
//     std::vector<int> quickunsorted_array = {1,3,5,4,-5,100,7777,2014};
//     //int low = unsorted_array[0];
//     //int high = unsorted_array[unsorted_array.size()-1];
//     BubbleSort bubble;
//     std::vector<int> bubblesorted_array = bubble.sort(bubbleunsorted_array);

//     QuickSort quick;
//     std::vector<int> quicksorted_array = quick.sort(quickunsorted_array);

//     for (int num : bubblesorted_array){
//         std::cout << num;
//     }
//     std::cout << std::endl;

//     for (int num : quicksorted_array){
//         std::cout << num;
//     }
//     std::cout << std::endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <sstream>
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    // Read input and convert sting to int vector
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> list;
    int num;
    while (iss >> num) {
        list.push_back(num);
    }

    // Sort using Quick Sort
    QuickSort quickSort;
    list = quickSort.sort(list);

    // Perform binary search for target = 1
    RecursiveBinarySearch binarySearch;
    bool result = binarySearch.search(list, 1);

    // Output result
    std::cout << (result ? "true" : "false") << " ";
    for (int num : list) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}