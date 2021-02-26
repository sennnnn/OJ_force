#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;


int findLongestSubString_dp(string s) {
    // 和常规的使用 dp 的方式不同, 能够使用 dp 最关键的一点是理解
    // 通过统计从 0 到该下标各个元素的 0, 1 个数之间的差值, 当两个下标的 0, 1 个数之间差值相同时, 靠前的下标到靠后的下标这中间
    // 一段子串是必然满足 0, 1 相等的。
    int length = s.size();
    int start, end, dist, max_dist = 0;
    int dp[100];
    for(int i = 1; i <= length; i++) {
        if(i == 1) dp[i] = s[i-1] == '0' ? -1 : 1;
        else {
            dp[i] = s[i-1] == '0' ? -1 : 1;
            dp[i] += dp[i-1];
        }
    }
    map<int, int> index_dict;
    for(int i = 1; i <= length; i++) {
        if(index_dict[dp[i]] == 0 && dp[i] != 0) {
            index_dict[dp[i]] = i;
        }else {
            start = index_dict[dp[i]];
            end = i;
            dist = end - start;
            if(dist > max_dist) max_dist = dist;
        }
    }
    return max_dist;
}


int main () {
    string s = "1101000";
    cout << findLongestSubString_dp(s) << endl;
}