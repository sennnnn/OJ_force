#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        for(auto i:nums) {
            dict[i]++;
        }
        int max_value = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            max_value = max(max_value, nums[i]);
        }
        int count = 0;
        while(1) {
            count += dict[max_value];
            if(count >= k) break;
            max_value--;
        }
        return max_value;
    }
};


int main() {
    Solution object;
    vector<int> nums = {23, 12, 3, 78, 218, -2, -33};
    int k = 3;
    cout << object.findKthLargest(nums, k) << endl;
}