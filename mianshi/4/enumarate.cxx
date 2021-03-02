#include <iostream>
#include <vector>

using namespace std;


int item_count;


void dfs(vector<int> nums, int S, int val, int n) {
    if(n == nums.size()) {
        if(val == S) item_count++;
        return;
    }
    dfs(nums, S, val+nums[n], n+1);
    dfs(nums, S, val-nums[n], n+1);
}


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        item_count = 0;
        dfs(nums, S, 0, 0);
        return item_count;
    }
};


int main() {
    Solution object;
    vector<int> nums = {1, 1, 1, 1, 1, 1};
    int S = 3;
    cout << object.findTargetSumWays(nums, S) << endl;
}