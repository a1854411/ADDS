#include <iostream>
#include "Heap.tpp"

int main() {
    std::vector<int> values = {4, 5, 3, 6, 1, 2};

    // Create a heap and heapify it
    Heap<int> myHeap(values);

    // Insert a new value into the heap
    myHeap.insert(7);

    // Print out the heap
    std::cout << "Heap elements: ";
    for (const auto& element : myHeap.values) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}