#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        int small = INT_MAX, mid = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(small >= nums[i]) small = nums[i];
            else if(mid >= nums[i]) mid = nums[i];
            else return true;
        }
        return false;
    }
};


int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution object;
    cout << object.increasingTriplet(nums) << endl;
}