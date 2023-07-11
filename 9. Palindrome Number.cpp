#include <iostream>
#include <list>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string str = std::to_string(x);
        std::list<char> mlist;
        for (int i = 0; i < str.size(); ++i){
            mlist.push_back(str[i]);
        }
        while (mlist.size() > 1){
            if (mlist.front() == mlist.back()){
                mlist.pop_front();
                mlist.pop_back();
            }
            else return false;
        }
        return true;
    }
};


int main(){
    Solution sol;
    std::cout << sol.isPalindrome(0);
}