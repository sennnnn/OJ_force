#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int ret;
        for(int i = 0; i < len; i++) {
            if(i == 0) ret = nums[i];
            else ret ^= nums[i];
        }
        return ret;
    }
};

int main() {
    Solution object;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    cout << object.singleNumber(nums) << endl;
}