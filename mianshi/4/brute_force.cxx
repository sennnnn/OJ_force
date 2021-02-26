#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;


int findLongestSubString(string s) {
    // 暴力遍历每一个子串来求值。
    int length = s.size();
    int max_count = -1;
    for(int i = 0; i < length; i++) {
        int zero_count = 0;
        int one_count = 0; 
        int length_count = 0;
        for(int j = i; j < length; j++) {
            if(s[j] == '0') zero_count++;
            if(s[j] == '1') one_count++;
            if(zero_count == one_count) {
                length_count = j - i + 1;
                if(length_count > max_count) max_count = length_count;
            }
        }
    }
    return max_count;
}


int main () {
    string s = "1101000";
    cout << findLongestSubString(s) << endl;
}