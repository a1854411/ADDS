#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize){
    if (numCrates <= loadSize){
        return 1;
    }
        if(numCrates % 2 == 0){
            return 2*numTrucks(numCrates/2, loadSize);
        }
        else{
            return numTrucks((numCrates/2)-0.5, loadSize) + numTrucks((numCrates/2)+0.5, loadSize);
        }
}