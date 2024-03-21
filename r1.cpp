#include <iostream>
#include <string>
#include <cmath>

int sum_of_powers(int n, int result){
    if (n==1){
        return 1;
    }
    return sum_of_powers(n-1, result + pow(n,n));
}
