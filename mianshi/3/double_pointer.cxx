#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        // 双指针法
        if(height.size() <= 2) return 0;
        int n = height.size();
        int left = 0, right = 0, count = 0;
        int left_index = 0, right_index = n - 1;
        while(left_index < right_index) {
            if(height[left_index] < height[right_index]) {
                if(height[left_index] > left) left = height[left_index];
                else count += left - height[left_index];
                left_index++;
            }else {
                if(height[right_index] > right) right = height[right_index];
                else count += right - height[right_index];
                right_index--; 
            }
        }
        return count;
    }
};


int main() {
    Solution object;
    vector<int> height = {4, 2, 3};
    cout << object.trap(height) << endl;
}