#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0;
        int n = height.size();
        int count = 0;
        int left, right, temp, distance, bar_height;
        stack<int> baseline;
        baseline.push(0);
        for(int i = 1; i < n;) {
            if(baseline.empty() || height[i] < height[baseline.top()]) {
                baseline.push(i);
                i++;
            }else {
                temp = height[baseline.top()]; baseline.pop();
                if(baseline.empty()) continue;
                bar_height = min(height[baseline.top()], height[i]) - temp;
                distance = i - baseline.top() - 1;
                count += distance*bar_height;
            }
        }
        return count;
    }   
};


int main() {
    Solution object;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << object.trap(height) << endl;
}