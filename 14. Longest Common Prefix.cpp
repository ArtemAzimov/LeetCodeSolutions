#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string result = "";
        int vecsize = strs.size();
        int stringsize = strs[0].size();

        if (vecsize == 1) {return result;}

        for (int istring = 0; istring < vecsize - 2; ++istring){
            for (int iword = 0; iword < stringsize; ++iword){
                if (strs[istring][iword] == strs[istring+1][iword]){ // Проход по всем?
                    result += strs[istring][iword];
                }
            }
        }
        return result;
    }
};


int main(){
    Solution sol;
    std::vector<std::string> strs {"flower","flow","flight","floradar"};
    // std::vector<std::string> strs {"dogcar","racecar","car"};
    std::cout << sol.longestCommonPrefix(strs);
}

