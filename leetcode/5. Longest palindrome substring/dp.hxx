#include <string>
#include <vector>

using namespace std;

class Solution_2 {
public:
    string longestPalindrome(string s) {
        if(s.length() == 0) return "";
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        string ret;
        ret.push_back(s[0]);
        int max_length = 1;
        int flag = 0;
        for(int i = 0; i < s.length(); i++){
            dp[i][i] = 1;
        }
        for(int j = 1; j < s.length(); j++){
            for(int i = 0; i < j; i++){
                if(i == j) {continue;}
                if(s[i] == s[j]) {
                    if((j - i) == 1) dp[i][j] = 2;
                    else dp[i][j] = dp[i+1][j-1] + 2;
                }else dp[i][j] = 1;
                if(dp[i][j] == (j - i + 1) && dp[i][j] > max_length){
                    ret = s.substr(i, j - i + 1);
                    max_length = j - i + 1;
                }
            }
        }
        return ret;
    }
};