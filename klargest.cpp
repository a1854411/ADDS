#include <vector>
#include <queue> // for priority_queue
using namespace std;

int kth_largest(vector<int> values, int k){
 std::priority_queue<int,    std::vector<int>, std::greater<int>> min_heap; // Define a min heap using priority_queue with greater comparator
     // Insert all elements of values into the min heap
    for (int val : values) {
        min_heap.push(val);

        // If the size of the heap exceeds k, remove the smallest element
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }

    // The kth largest element will be at the top of the min heap
    return min_heap.top();
}