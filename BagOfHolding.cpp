#include <iostream>
#include <string>
#include "BagOfHolding.h"


void BagOfHolding::addItem(std::string item){
    bag.push_back(item);
}

std::string BagOfHolding::removeItem(){
    srand(time(NULL));

    int spot = rand() % bag.size();
    std::string item = bag.at(spot);
    bag.erase(bag.begin() + spot);

}

std::string BagOfHolding::removeItem(std::string itemRemoved){
    for (int i=0; i < bag.size(); i++){
        if (bag[i] == itemRemoved){
            std::string item = bag.at(i);
            bag.erase(bag.begin() + i);
            return item; 
        }
    }
    return NULL;
}