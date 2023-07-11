#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mapMag;
        
        for (char ch : magazine){
            unordered_map<char, int>::iterator it = mapMag.find(ch);
            if (it != mapMag.end()){
                ++(it->second);
            }
            else{
                mapMag.insert(pair<char, int>(ch, 0));
            }
        }

        char array[ransomNote.size()];
        for (int i = 0; i < ransomNote.size(); ++i){
            array[i] = ransomNote[i];
        }

        for (char ch : array){
            unordered_map<char, int>::iterator it = mapMag.find(ch);
            if (it != mapMag.end()){
                if (it->second < 0){
                    return false;
                }
                else{
                    --(it->second);
                }
            }
            else return false;
        }
        return true;
    }
};