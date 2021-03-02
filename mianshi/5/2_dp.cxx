#include <iostream>
#include <vector>

using namespace std;


int max(int a, int b) {
    return a > b ? a : b;
}


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j]+1);
                if(dp[i] >= 3) return true;
            }
        }
        return false;
    }
};


int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution object;
    cout << object.increasingTriplet(nums) << endl;
}