#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include "Node.h"
#include <vector>
#include <string>

class PrefixMatcher{
    private:
        Node* root;
    public:
        PrefixMatcher();
        int selectRouter(std::string networkAddress);  // return the router with the longest matching prefix
        void insert(std::string address, int routerNumber); // add a router address

};
#endif