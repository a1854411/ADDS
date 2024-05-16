#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <cmath>  // for floor
#include <iostream>
using namespace std;

template <typename T>

class Heap {
    private:
        std::vector<T> values;
        void heapify(int);

    public:
        Heap();  // constructs an empty heap

        // constructs a heap with the values from the given vector
        // the type T MUST provide comparison operators <, >, ==
        Heap(std::vector<T>);

        void insert(T);
        void remove(T);
        T getMin();
};

template <typename T>
Heap<T>::Heap() {}


/*******************************/
// constructs a heap with the values in the given vector
// the type T MUST provide comparison operators <, >, ==
/*******************************/
template <typename T>
Heap<T>::Heap(std::vector<T> start_values) {
  // copy the values into our heap vector
  for (int i = 0; i < start_values.size(); i++) {
    values.push_back(start_values.at(i));
  }

  // starting from last non-leaf node (last parent), heapify each
  // of the parents
  int initial_parent_index = floor(values.size() / 2) - 1;
  for (int parent_index = initial_parent_index; parent_index >= 0;
       parent_index--) {
    heapify(parent_index);
  }
}

// insert value to the heap
template <typename T>
void Heap<T>::insert(T value) {
    values.push_back(value);
    int child_index = values.size() - 1;
    int parent_index = (child_index - 1) / 2;

    while (child_index > 0 && values[child_index] < values[parent_index]) {
        std::swap(values[child_index], values[parent_index]);
        child_index = parent_index;
        parent_index = (child_index - 1) / 2;
    }
}

/* delete values from the heap */
template <typename T>
void Heap<T>::remove(T value) {
    auto it = std::find(values.begin(), values.end(), value);
    if (it != values.end()) {
        size_t index = std::distance(values.begin(), it);
        std::swap(values[index], values.back());
        values.pop_back();
        if (index < values.size()) {
            if (index > 0 && values[index] < values[(index - 1) / 2]) {
                // If the swapped value is less than its parent, bubble up
                while (index > 0 && values[index] < values[(index - 1) / 2]) {
                    std::swap(values[index], values[(index - 1) / 2]);
                    index = (index - 1) / 2;
                }
            } else {
                // If the swapped value is greater than or equal to its parent, sink down
                while (2 * index + 1 < values.size()) {
                    size_t min_child = 2 * index + 1;
                    if (2 * index + 2 < values.size() && values[2 * index + 2] < values[min_child]) {
                        min_child = 2 * index + 2;
                    }
                    if (values[index] <= values[min_child]) break;
                    std::swap(values[index], values[min_child]);
                    index = min_child;
                }
            }
        }
    }
}



// find the smallest value in the heap
template <typename T>
T Heap<T>::getMin() {
    if (values.empty()) {
        // If the heap is empty, return a default-initialized value of type T
        return T();
    }
    // The smallest value is always at the root (index 0) in a min-heap
    return values[0];
}

// private function to heapify a given 'node'
template <typename T>
void Heap<T>::heapify(int parent_index) {
  // if we're outside the index range, return
  if (parent_index < 0 || parent_index >= values.size()) return;

  // find children indexes
  int left_child_index = parent_index * 2 + 1;
  int right_child_index = parent_index * 2 + 2;

  // if parent is larger than child, swap with smallest child
  int index_of_smallest = parent_index;

  // check if left child exists and if exists, is smallest value there
  if (left_child_index < values.size() &&
      values.at(left_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = left_child_index;
  }

  // check if left child exists and if exists, is smallest value there
  if (right_child_index < values.size() &&
      values.at(right_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = right_child_index;
  }

  // if parent is not smallest, swap with smallest child
  if (index_of_smallest != parent_index) {
    T temp = values.at(parent_index);
    values.at(parent_index) = values.at(index_of_smallest);
    values.at(index_of_smallest) = temp;
  }

  // move up the 'tree' to grandparent
  heapify(floor(parent_index / 2) - 1);
}

#endif