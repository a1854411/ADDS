#include "Finder.h"

std::vector<int> Finder::findSubstrings(std::string s1, std::string s2){
    std::vector<int> result; //initialise vector to be filled with indexes of s2 prefixes in s1
    for(size_t startPos = 0; startPos <= s2.size(); ++startPos) {
        size_t found = s1.find(s2.substr(0, startPos), startPos); //where found is the vector index position in s1

        if (found != std::string::npos) { //if position of prefix is not the same as the already found postition 
            result.push_back(found); //add index position to result vector
            startPos = found + 1;
        } else {
            result.push_back(-1); //add -1 to result vector
        }
    }
return result;
}
