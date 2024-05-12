#include "PrefixMatcher.h"
#include "Node.h"
#include <string>

using namespace std;

PrefixMatcher::PrefixMatcher() 
{
    root = new Node();
}

int PrefixMatcher::selectRouter(string networkAddress) {
    Node* curr = root;
    int prefix_length = 0;
    int router_number = -1;

    for (const char c : networkAddress){
        if (curr->children.count(c) == 0){
            break;}
        curr = curr->children[c];
        prefix_length++;
        if (curr->word_check){
            router_number = curr->id;}
    }
    return router_number;
}

void PrefixMatcher::insert(string address, int routerNumber){
    Node* curr = root;
    for (const char a : address){
        if (curr->children.count(a) == 0){
            curr->children[a] = new Node(curr->depth + 1);
        }
        curr = curr->children[a];
    }
    curr->word_check = true;
    curr-> id = routerNumber;
}
