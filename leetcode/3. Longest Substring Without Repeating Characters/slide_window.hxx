#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        int hash_value[128];
        for(int i = 0; i < 128; i++) hash_value[i] = 0;
        int l = 0, r = 0;
        int max_length = -1;
        char item;
        while(r<s.length()){
            item = s[r];
            if(hash_value[item] == 0){
                hash_value[item] = 1;
            }else{
                for(; l < r; l++){
                    if(hash_value[item] == 0) break;
                    hash_value[s[l]] = 0;
                }
                hash_value[item] = 1;
            }
            r++;
            if((r - l) > max_length){
                max_length = r - l;
            }
        }
        return max_length;
    }
};