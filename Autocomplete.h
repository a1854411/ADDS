#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include "Node.h"
#include <vector>
#include <string>

using namespace std;

class Autocomplete {
private:
    Node* root;
public:
    Autocomplete();
    vector<string> getSuggestions(string partialWord);  // return the known words that start with partialWord
    void insert(string word); // add a word to the known words
};
#endif