#include <iostream>
#include <regex>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        int result = 0;

        std::unordered_map<int, std::string> mp;
        mp.insert({
            {1,"I"},
            {4,"IV"},
            {5,"V"},
            {9,"IX"},
            {10,"X"},
            {40,"XL"},
            {50,"L"},
            {90,"XC"},
            {100,"C"},
            {400,"CD"},
            {500,"D"},
            {900,"CM"},
            {1000,"M"}
        });
        
        std::regex reg ("(I[VX])|(X[LC])|(C[DM])|([IVXLCDM])");
        std::smatch match;
        auto words_begin = std::sregex_iterator(s.begin(), s.end(), reg);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i){
            for (auto it = mp.begin(); it != mp.end(); ++it){
                if (it->second == (*i).str()){
                    result += it->first;
                }
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