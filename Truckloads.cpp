#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize){
    if (numCrates <= loadSize){
        return 1;
    }
    else{
        //divide numCrates into two piles
            return 2*numTrucks(numCrates/2, loadSize);  
        }


    }