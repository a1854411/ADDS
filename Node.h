#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
    friend class LinkedList;
    private:
        int data;
        Node* link;
    public:
        Node(int data, Node*);
        int get_data();
};

#endif