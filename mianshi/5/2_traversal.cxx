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
        vector<int> min_collect(n, nums[0]);
        vector<int> max_collect(n, nums.back());
        for(int i = 1; i < n; i++) {
            min_collect[i] = min(min_collect[i-1], nums[i]);
        }
        for(int i = n - 2; i >= 0; i--) {
            max_collect[i] = max(max_collect[i+1], nums[i]);
        }
        for(int i = 1; i < n-1; i++) {
            if(nums[i] > min_collect[i] && nums[i] < max_collect[i]) return true;
        }
        return false;
    }
};


int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution object;
    cout << object.increasingTriplet(nums) << endl;
}