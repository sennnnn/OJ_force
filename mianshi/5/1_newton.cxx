#include <math.h>
#include <iostream>

using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        double x0, x1;
        x0 = x;
        while(1) {
            x1 = x0 - (x0*x0 - x) / (2 * x0);
            if(fabs(x1 - x0) < 1e-7) break;
            x0 = x1;
        }
        return (int)x0;
    }

    int myCube(int x) {
        if(x == 0) return 0;
        double x0, x1;
        x0 = x;
        while(1) {
            x1 = x0 - (x0*x0*x0 - x) / (3 * x0 * x0);
            if(fabs(x1 - x0) < 1e-7) break;
            x0 = x1;
        }
        return (int)x0;
    }
};


int main() {
    Solution object;
    int x = 289189;
    cout << object.myCube(x) << endl;
}