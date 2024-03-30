#include "Finder.h"
using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2){
    vector<int> result; //initialise vector to be filled with indexes of s2 prefixes in s1
    for(size_t i = 1; i <= s2.size(); i++) {
        size_t found = s1.find(s2.substr(0, i)); //where found is the vector index position in s1

        if (found != string::npos) { //if position of prefix is not the same as the already found postition 
            result.push_back(found); //add index position to result vector
        } else {
            result.push_back(-1); //add -1 to result vector
        }
    }
return result;
}
