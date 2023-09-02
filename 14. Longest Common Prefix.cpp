#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string result = "";

        std::vector<int> word_sizes;
        
        for (const auto& word : strs){
            word_sizes.push_back(word.size());
        }

        for (int i = 0; i < word_sizes.size() - 1; ++i){
            if (word_sizes[i] > word_sizes[i+1]){
                int temp = word_sizes[i+1];
                word_sizes[i+1] = word_sizes[i];
                word_sizes[i] = temp;
            }
        }

        int min_size = word_sizes[0];

        std::set<char> temp_set;
        std::set<char> char_set;
        int counter = 0;

        while(counter != min_size){
            for (const auto& word : strs){
                if (!word.empty()){
                    temp_set.insert(word[counter]);
                    std::cout << "word[counter]: " << word[counter] << std::endl;
                }
                if (temp_set.size() == counter){
                    std::cout << "counter: " << counter << std::endl;
                    std::cout << "temp_set.size(): " << temp_set.size() << std::endl;
                    result += word[counter];
                    ++counter;
                }
                else {
                    break;
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
    // std::vector<std::string> strs {"sda","ggg","rrr"};
    // std::vector<std::string> strs {""};
    // std::vector<std::string> strs {"",""};
    // std::vector<std::string> strs {"a"};
    // std::vector<std::string> strs {"flower","flower","flower","flower"};

    std::cout << sol.longestCommonPrefix(strs);
}