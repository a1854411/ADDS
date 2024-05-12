#include "node.h"


Node::Node(){
    this->word_check = false;
    this->depth = 0;
    this->id = 0;
}

Node::Node(int depth){
    this->depth = depth;
    this->word_check = false;
    this->id = 0;
}

void Node::insert(const string& word){
    Node* curr = this;
    for (const char a : word){
        if (curr->children.count(a) == 0){
            depth = curr->depth+1;
            curr->children[a] = new Node(depth+1);}
        curr = curr->children[a];
    }
curr->word_check = true; //to state this is the end of a word
}

vector<string> Node::getSuggestions(const string& partialWord) const {
    Node* curr = const_cast<Node*>(this);
    for (const char a : partialWord){
        if (curr->children.count(a)==0){
            return{};}
            curr = curr->children[a];
    }
    vector<string> suggestions;
    if (curr->word_check){
        suggestions.push_back(partialWord);}
    storeWords(curr, partialWord, suggestions);
    return suggestions;
}

void Node::storeWords(Node* node, string prefix, vector<string>& autofill) const{
    if (node->word_check){
        autofill.push_back(prefix);}
    for (auto it = node->children.begin(); it != node->children.end(); ++it){
        char a = it->first;
        Node* child = it->second;
        storeWords(child, prefix + a, autofill);
    }
}