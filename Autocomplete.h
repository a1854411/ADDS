// #ifndef AUTOCOMPLETE_H
// #define AUTOCOMPLETE_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Node {
    friend class Autocomplete;

    private: 
        bool isEndOfWord = false; //to see the end of the word
        std::unordered_map<char,Node *> children;
};


class Autocomplete {
    private:
        Node* root = new Node();

    public:
        std::vector<std::string> getSuggestions(std::string partialWord){ // return the known words that start with partialWord
            std::vector<std::string> result = [];
            Node *current = root;

        }

        void insert(std::string word){ // add a word to the known words
            Node *current = root;
            for(auto &c : word){
                std::string character(1,c);
                if(current->childrenMap.find(character) == current->childrenMap.end()){
                    current->childrenMap.insert({character, new Node()});
                }
                current = current->childrenMap.find(character)->second;
            }
            current->isEndOfWord = true;
        }

        void searchAllForPrefix(Node *node, std::string prefix, std::vector<std::string> &result);
};

// #endif