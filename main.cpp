#include "Finder.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    string s1 = "464554567";
    string s2 = "45689";

    Finder finder;
    vector<int> indices = finder.findSubstrings(s1, s2);

    // Print out the indices
    cout << "Indices: ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}