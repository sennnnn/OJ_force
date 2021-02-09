#include <string>
#include <vector>

using namespace std;

int l;
int r;
int max_length;

void diffusion(string s, int l_m, int r_m) {
    while(1) {
        if(l_m >= 0 && r_m < s.length() && s[l_m] == s[r_m]) {
            if((r_m - l_m + 1) > max_length) {
                max_length = r_m - l_m + 1;
                l = l_m;
                r = r_m;
            }
            l_m--;
            r_m++;
        }else return;
    }
}


class Solution_3 {
public:
    string longestPalindrome(string s) {
        if(s.length() == 0) return "";
        string ret;
        ret.push_back(s[0]);
        max_length = 1;
        for(int i = 0; i < s.length()-1; i++) {
            diffusion(s, i, i);
            diffusion(s, i, i+1);
        }
        if(max_length != 1) {
            ret = s.substr(l, max_length);
        }
        return ret;
    }
};