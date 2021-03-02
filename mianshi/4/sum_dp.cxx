#include <iostream>
#include <vector>

using namespace std;

int dp[21][4001];


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 1) {
            if(S == nums[0] || S == -1*nums[0]) return 1;
            else return 0;
        }
        for(int i = 0; i < 21; i++) {
            for(int j = 0; j < 4001; j++) {
                dp[i][j] = 0;
            }
        }
        dp[1][nums[0]+2000] += 1;
        dp[1][-1*nums[0]+2000] += 1;
        for(int i = 2; i <= nums.size(); i++) {
            for(int j = -1000; j <= 1000; j++) {
                dp[i][j+2000] = dp[i-1][j-nums[i-1]+2000] + dp[i-1][j+nums[i-1]+2000];
            }
        }
        if(S > 1000 || S < -1000) return 0;
        else return dp[nums.size()][S+2000];
    }
};


int main() {
    Solution object;
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    int S = 4;
    cout << object.findTargetSumWays(nums, S) << endl;
}