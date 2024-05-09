#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <unordered_map>


class Node {
    friend class Autocomplete;

    bool isEndOfWord;
    std::unordered_map<char,Node *> children;

    Node()
};

#endif