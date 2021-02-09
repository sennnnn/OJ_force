#include <string>

class Solution_1 {
public:
    std::string longestPalindrome(std::string s) {
        if(s.length() == 0) return "";
        std::string ret;
        ret.push_back(s[0]);
        int max_length = 1;
        int flag = 0;
        for(int i = 1; i < s.length(); i++){
            for(int j = 0; j < i; j++){
                flag = 1;
                for(int k = j; k <= (i+j)/2; k++){
                    if(s[k] != s[i+j-k]) flag = 0;
                }
                if(flag){
                    if((i - j + 1) > max_length){
                        max_length = i - j + 1;
                        ret = s.substr(j, i - j + 1);
                    }
                }
            }
        }
        return ret;
    }
};