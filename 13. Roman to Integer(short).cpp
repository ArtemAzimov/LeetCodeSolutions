#include <iostream>
#include <regex>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        int result = 0;

        std::unordered_map<char, int> mp;
        mp.insert({
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        });
        
        for (int i = 0; i < s.size(); ++i){
            if (mp[s[i]] < mp[s[i+1]]){
                result = result - mp[s[i]];
            }
            else {
                result += mp[s[i]];
            }
        }

        return result;
    }
};


int main(){
    std::string user_str = ("MCMXCIV");
    Solution sol;
    std::cout << sol.romanToInt(user_str) << std::endl;
}