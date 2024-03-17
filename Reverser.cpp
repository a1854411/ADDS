#include <tgmath.h>
#include <string>
#include "Reverser.h"

int Reverser::reverseDigit(int digit){
    if(digit < 10 && digit > 0){
        return digit;
    }
    if(digit < 0){
        return -1;
    }
    else{ 
        int digit_reversed = digit % 10;
        int digit_divided = digit / 10;
        int digit_result = (int)log10(digit_divided) + 1;
        return digit_reversed * pow(10, digit_result) + reverseDigit(digit_divided); 
    }
}

std::string Reverser::reverseString(std::string string){
    if(string.length() <= 1 && string.length() > 0){
        return string;
    }
    if(string.empty()){
        return "ERROR";
    }
    else{
        return reverseString(string.substr(1)) + string[0]; 
    }
}
