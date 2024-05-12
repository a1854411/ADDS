#include "Autocomplete.h"
#include "Node.h"

Autocomplete::Autocomplete(){
    root = new Node();
}

vector<string> Autocomplete::getSuggestions(string partialWord){
    return root->getSuggestions(partialWord);
}

void Autocomplete::insert(string word){
    root->insert(word);
}