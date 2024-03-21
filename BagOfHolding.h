#include <iostream>
#include <vector>

#ifndef BAGOFHOLDING_H
#define BAGOFHOLDING_H

template<class B>

class BagOfHolding {
    private:
        std::vector<B> bag; 
    public:
        void addItem(B item){
            bag.push_back(item);
        }

        B removeItem(){
            srand(time(nullptr));
            int spot = rand() % bag.size();
            B item = bag.at(spot);
            bag.erase(bag.begin() + spot);
            return item;
        }

        B removeItem(B itemRemoved){
            for (int i=0; i < bag.size(); i++){
                if (bag[i] == itemRemoved){
                    B item = bag.at(i);
                    bag.erase(bag.begin() + i);
                    return item; 
                }
            }
            return nullptr;

        }
};

#endif