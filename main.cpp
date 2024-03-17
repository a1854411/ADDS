#include <iostream>
#include "Truckloads.h"
#include "Reverser.h"
using namespace std;

int main(){
    Truckloads trucks;
    int truckLoads1 = trucks.numTrucks(42,7);
    std::cout << truckLoads1 << std::endl;

    Reverser digit;
    int reversed_digit = digit.reverseDigit(00421);
    std::cout << reversed_digit << std::endl; 

    Reverser string;
    std::string reversed_string = string.reverseString("aaabaa");
    std::cout << reversed_string << std::endl; 
}