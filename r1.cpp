#include <iostream>
#include <string>
#include <cmath>

int sum_of_powers(int n){
    if (n==1){
        return 1;
    }
    //return sum_of_powers(n-1, acc + pow(n,n));
    return sum_of_powers(n - 1) + pow(n,n);
}

//int main(){
    //std::cout << sum_of_powers(5) << std::endl;
//}