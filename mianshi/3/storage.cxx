#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        // 针对常规的暴力方法, 使用了额外的数组 left_max right_max 来存储每一个位置的左右边界柱
        if(height.size() <= 2) return 0;
        int n = height.size();
        int left = 0, right = 0, count = 0;
        vector<int> left_max, right_max;
        for(int i = 0; i < n; i++) {
            if(height[i] > left) left = height[i];
            left_max.push_back(left);
        }
        for(int i = n - 1; i >= 0; i--) {
            if(height[i] > right) right = height[i];
            right_max.push_back(right);
        }
        for(int i = 1; i < n - 1; i++) {
            count += min(left_max[i], right_max[n-1-i]) - height[i];
        }
        return count;
    }
};


int main() {
    Solution object;
    vector<int> height = {4, 2, 3};
    cout << object.trap(height) << endl;
}