#include <iostream>
#include <math.h>

using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return x;
        int left = 0, right = x, ans;
        while(left <= right) {
            int mid = (left + right) / 2;
            if((long long)mid*mid <= x) {
                ans = mid;
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return ans;
    }
    int myCube(int x) {
        if(x == 0) return x;
        int left = 0, right = x, ans;
        while(left <= right) {
            int mid = (left + right) / 2;
            if((long long)mid*mid*mid <= x) {
                ans = mid;
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return ans;
    }
};


int main() {
    Solution object;
    int x = 277333;
    cout << object.myCube(x) << endl;
}