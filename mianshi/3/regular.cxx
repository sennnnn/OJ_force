#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        // 暴力搜索法直接搜索到每一个位置的左右两个边界柱子, 从而计算得到该位置能够储存的雨水。
        if(height.size() <= 2) return 0;
        int n = height.size();
        int left = 0, right = 0, count = 0;
        for(int i = 1; i < n - 1; i++) {
            for(int j = i; j < n; j++) {
                left = max(left, height[j]);
            }
            for(int j = i; j > 0; j--) {
                right = max(right, height[j]);
            }
            count += min(left, right) - height[i];
        }
        return count;
    }
};


int main() {
    Solution object;
    vector<int> height = {4, 2, 3};
    cout << object.trap(height) << endl;
}