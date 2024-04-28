#ifndef BIGNUMCALC_H
#define BIGNUMCALC_H

#include <iostream>
#include <string>
#include <list>

class BigNumCalc {
    public:
        std::list<int> buildBigNum(std::string numString);
        std::list<int> add(std::list<int> num1, std::list<int> num2);
        std::list<int> sub(std::list<int> num1, std::list<int> num2);
        std::list<int> mul(std::list<int> num1, std::list<int> num2);
};

#endif

#include <list>
#include <string>
#include <algorithm>
#include "BigNumCalc.h"
using namespace std;

list<int> BigNumCalc::buildBigNum(string numString){
    list<int> result;
    for(char string : numString){
        result.push_back(string - '0');}
    return result;
}

list<int> BigNumCalc::add(list<int>num1, list<int> num2){
    list<int> result;

    int carry = 0;

    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();

    while(it1 != num1.rend() || it2 != num2.rend() || carry !=0){
        int sum = carry;
        if (it1 != num1.rend()){
            sum += *it1;
            it1++;}
        if (it2 != num2.rend()){
            sum += *it2;
            it2++;}
        result.push_front(sum % 10);
        carry = sum/10;}
    return result;
}

list<int> BigNumCalc::sub(list<int> num1, list<int> num2){
    list<int> result;

    int borrow = 0;

    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();

    while (it1 != num1.rend() || it2 != num2.rend()){
        int diff = borrow;
        
        if (it2 != num2.rend()){
            diff += *it1;
            it1++;}

        if (it2 != num2.rend()){
            diff -= *it2;
            it2++;
        }

        if (diff < 0){
            diff += 10;
            borrow = -1;
        }else{
            borrow = 0;
        }
        result.push_front(diff);
    }

    while(!result.empty() && result.front() == 0){
        result.pop_front();
    }
    return result;
}

list<int> BigNumCalc::mul(list<int> num1, list<int> num2){

    list<int> result;

    int carry = 0;

    for (auto i = num1.rbegin(); i != num1.rend(); i++){
        int num = (*i)*num2.front()+carry;
        carry = num/10;
        num = num % 10;
        result.push_front(num);
    }

    if(carry > 0){
        result.push_front(carry);
    }
    return result;
}