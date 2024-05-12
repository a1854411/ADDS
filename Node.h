#ifndef NODE_H
#define NODE_H
#include <vector>
#include <unordered_map>
#include <string>


using namespace std;

class Node{
private:
    int depth;
    int id;
    unordered_map<char, Node*> children;
    bool word_check;
    void storeWords(Node* node, string prefix, vector<string>& autofill) const;
    friend class Autocomplete;
    friend class PrefixMatcher;
public:
    Node();
    Node(int depth);
    void insert(const string& word);
    vector<string> getSuggestions(const string& partialWord) const;
};
#endif