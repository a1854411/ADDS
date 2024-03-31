#include "Finder.h"

std::vector<int> Finder::findSubstrings(std::string s1, std::string s2){
    std::vector<int> result;
    bool possible=true;
    size_t startPos=0;
    //fill vector with indexes of s2 and prefixes in s1
    for(size_t i = 0; i <= s2.size(); ++i) { //changed startpos to index
        if(possible==false){
            result.push_back(-1);
        }else {
            size_t found = s1.find(s2.substr(0, i), startPos);
            if (found != std::string::npos)
            {
            result.push_back(found);
            startPos = found; //got rid of the +1
            }
            else
            {
                result.push_back(-1);
                possible=false;
            }
        }
    }
return result;
}
